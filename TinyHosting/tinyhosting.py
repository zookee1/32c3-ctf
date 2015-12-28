__author__ = 'ahallmann'

import requests
import re
import sys

r = requests.post("http://136.243.194.53/",
      data={
          'filename': 'foo',
          'content': '<?php 1;\n'
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
print("got " + url)

r = requests.get(url)
if r.status_code != 200:
    print(r.status_code, r.reason)
    print(r.text)
    sys.exit(1)


print r.text