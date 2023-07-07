import numpy as np
import matplotlib.pyplot as plt
import cv2

img_path = './cat.png'

img = cv2.imread(img_path)
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

print(gray.shape)
width, height = gray.shape

# print(gray)

file = open("encoded.txt","wb")
file.write(gray)
file.close()

decoded = open("encoded.txt","rb")
cnt = 0

# let's define the image widht and height
dec = np.zeros((width,height),int)
w=0
h=0

print(dec.shape)

for val in decoded:
    for d in val:
        cnt=cnt+1
        # print(d,end=" ")
        
        dec[w][h]=d
        h = h+1

        if(h%height==0):
            w = w+1
            h=0
    # print(cnt)

plt.imshow(dec,cmap='gray')
plt.show()