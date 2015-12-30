import binascii, re, struct

#~ bitlist = ['AB', 'EC', 'CD', 'AB', 'ED', 'EB', 'DB', 'AB', 'EC']
#~ bytes = binascii.a2b_hex(''.join(bitlist))

with open("dump.hex", "rb") as f:
    lines = f.read().split("\n")

def swap_bytes(original):
    return ''.join([c for t in zip(original[1::2], original[::2]) for c in t])
'\xde\xad\xc0\xde'

with open("dump.out", "wb") as f:
    #000010 000002 000076 000001 000000 002100 000100 000000 000000
    for line in lines:
        bitlist = re.findall(r"\d\d", line)
        bitlist = bitlist[6:]
        print(bitlist)

        my_bytes = map(lambda x: chr(int(x, 8)), bitlist)
        print(my_bytes)
        #~ for b in my_bytes:
            #~ f.write(b)
        my_bytes = ''.join(my_bytes)
        my_bytes = swap_bytes(my_bytes)
        
        #~ my_bytes = binascii.a2b_hex(''.join(bitlist))
        f.write(my_bytes)
        #~ f.write(struct.pack('<c', my_bytes))
        break   
        
        #~ line_parts = line.split(" ")
        #~ line_parts = line_parts[1:]
        #~ print(line_parts)
        #~ break
