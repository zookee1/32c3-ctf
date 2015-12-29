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
r = requests.get("http://136.243.194.46/public/show_comment?id=4c735ae8-91f2-45a8-a6db-56b5ebd197b3")
print(r.status_code, r.reason)
print(r.text)
