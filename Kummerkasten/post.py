__author__ = 'ahallmann'

import requests
import time

list = ['OK','super','nice']

for word in list:
    time.sleep(35) #to not exceed rate limit
    r = requests.post("http://136.243.194.46/public/add_comment",
        data={
            'username': '32c3',
            'comment': word
        }
    )

    print(r.status_code, r.reason)
    print(r.text)
