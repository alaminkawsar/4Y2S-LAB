
from base64 import encode

file = open("./LZW-Dictionary-Based-Codign/input.txt", "r")
message = str(file.read())
# print(message)

dictionary = {}

# make dictionary
for ch in message:
    dictionary[ch]=ord(ch)


# initialize s 
s = message[0]
code = 256

# encoder empty list
encoder = []

print('\nLZW Compression:\n')
print(' s \tc \toutput \tcode \tstring')
print('---------------------------------------')

# initial dictionary print
for key in dictionary.keys():
    # print(dictionary[key])
    print('\t \t  \t{}  \t{}'.format(str(dictionary[key]),str(key)))

print('---------------------------------------')

for i in range(1,len(message)):
    c = message[i]
    if (s+c) in dictionary:
        s = s+c
    else:
        encoder.append(dictionary[s])
        print('{}  \t{} \t{}  \t{}  \t{}'.format(s,c,str(dictionary[s]),code,str(s+c)))
        #print(s,dictionary[s])
        dictionary[s+c]=code
        s=c
        code = code + 1

encoder.append(dictionary[s])
print('{}  \tEOF \t{}'.format(s,dictionary[s]))

file = open("./LZW-Dictionary-Based-Codign/encoded.txt", "w")
file.write(str(encoder))
# joblib.dump(encoder,'./LZW-Dictionary-Based-Codign/encoded.sav')