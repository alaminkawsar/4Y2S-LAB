
# ascii dictionary
dictionary = {}
for i in range(0,256):
    dictionary[i] = chr(i)
# dictionary = dictionary[1:-1]
# print(dictionary)

file = open("./LZW-Dictionary-Based-Codign/encoded.txt", "r")
sequence = file.read()
sequence = sequence[1:-1]
sequence = sequence.split(', ')
sequence = [int(x) for x in sequence]
print(sequence)

s = ""
code = 256
entry = ""
num = 0
dec=1
output = 
for k in sequence:
    entry = dictionary[k]

    print(entry)
    entry = str(entry)
    if(s!=""):
        dictionary[code]=s+entry[0]
        code  = code + 1
    s = entry
