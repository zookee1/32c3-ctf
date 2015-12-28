__author__ = 'ahallmann'

import requests
r = requests.post("http://136.243.194.46/public/add_comment",
    data={
        'username': 'user',
        'comment': 'test'
    }
)
print(r.status_code, r.reason)
print(r.text)
