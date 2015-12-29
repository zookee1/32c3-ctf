import socket, sys, time, struct, re, random
from pprint import pprint

def stuff(numbers):
    HOST, PORT = "136.243.194.45", 1024
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))

    data = s.recv(1024)
    print(data)

    data = s.recv(1024)
    print(data)

    for n in numbers:
        print("> %s" % n)
        msg = "%s\n" % n
        n = s.send(msg)
        if n != len(msg):
            error("not send enough")

        data = s.recv(1024)
        print("< %s" % data)

    data = s.recv(1024)
    while data:
        print("< %s" % data)
        data = s.recv(1024)
    

def foo():
    #~ s.sendall(sys.argv[1])
    n = s.send(msg)
    if n != len(msg):
        error("not send enough")
    data = s.recv(1024)

    magic = '\x15\x03\x03\x00\x02\x02('
    #~      '\x15\x03\x03\x00\x02\x022'
    #~ print(repr(data))
    if data != magic:
        print(repr(data))
    return data != magic

#stuff(range(26))

def foo2():
    HOST, PORT = "136.243.194.45", 1024
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))

    f = s.makefile()
    def get_line():
        line = f.readline().strip()
        print("< %s" % line)
        return line
        
    while get_line() != "Which numbers do you want to choose?":
        pass
    
    data = s.recv(1024)
    print("< %s" % data)
    
def stuff2(numbers):
    print("time: %s" % time.time())
    
    HOST, PORT = "136.243.194.45", 1024
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((HOST, PORT))
    
    def wait_for(s2):
        data = s.recv(1024)
        print("< %s$" % data)
        while not data.endswith(s2):
            #~ print("foo")
            recv_data = s.recv(1024)
            print("< %s$" % recv_data)
            if not recv_data:
                raise Exception("no more data")            
            data = data + recv_data
            #~ print("bar")
        #~ print("< %s$" % data)
        return data

    def send_msg(msg):
        #~ msg = "%s\n" % n
        n = s.send(msg)
        if n != len(msg):
            raise Exception("not send enough")
        print("> %s" % msg)

    while True:
        #Please enter your number for field 1:1:
        wait_for("Please enter your number for field 1:1: ")
        send_msg("99999\n")


        #This number is too big, maximum for the current difficulty is 31.
        #~ wait_for(".")
        tmp = wait_for("Please enter your number for field 1:1: ")
        max_num = re.findall("\d+", tmp)[0]
        max_num = int(max_num)
        print("max_num: %s" % max_num)

        numbers = range(max_num + 1)
        random.shuffle(numbers)
        numbers = numbers[:25]
        print(numbers)

        send_msg("%s\n" % numbers[0])
        for n in numbers[1:]:
            tmp = wait_for(": ")
            send_msg("%s\n" % n)

        #~ if raw_input("quit?") == 'q':
            #~ break
    #~ wait_for("Please enter your number for field 1:1: ")

    #~ data = s.recv(1024)
    #~ print("< %s$" % data)
#~ 
    #~ data = s.recv(1024)
    #~ print("< %s$" % data)

    
stuff2(None)    
