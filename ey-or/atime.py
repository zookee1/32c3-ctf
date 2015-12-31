import time
import subprocess
import string


def time_pwd_often(pwd):
    cnt = 1000
    sum = 0.0

    for i in range(cnt):
        sum += time_pwd(pwd)

    return sum / float(cnt)

def time_pwd(pwd):
    start = time.clock()
    ps = subprocess.Popen('./time', stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.STDOUT)
    ps.communicate(pwd + "\n")
    ps.wait()
    return time.clock() - start


results = []

chars = string.ascii_letters + string.digits
for c in chars:
    c = "" + c
    t = time_pwd_often(c + "XXX")
    print(str(t) + ": " + c)
    results.append((t, c))

print("done, sorting ...")
print("-------------")
print("-------------")
print("-------------")
results.sort()
for t,c in results:
    print(str(t) + ": " + c)