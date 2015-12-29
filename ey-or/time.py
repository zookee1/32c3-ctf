import time
import subprocess
import string


def time_pwd(pwd):
    start = time.clock()
    ps = subprocess.Popen('./ey_or', stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.STDOUT)
    ps.communicate(pwd + "\n")
    ps.wait()
    return time.clock() - start


results = []

chars = string.ascii_letters + string.digits
for c in chars:
    c = "a" + c
    t = time_pwd(c)
    results.append((t, c))

results.sort()
for t,c in results:
    print(str(t) + ": " + c)