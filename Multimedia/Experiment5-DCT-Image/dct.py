import numpy as np
from scipy.fftpack import dct, idct
import matplotlib.pyplot as plt
import cv2

# Define the 16x16 grayscale image
img = cv2.imread('/home/kawsar/Desktop/Class_Resource/4th year 2nd Semester/Multimedia/Multimedia-Lab/Experiment5-DCT-Image/flower.png')
img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

# Apply DCT to the imqage
dct_img = dct(dct(img, axis=0, norm='ortho'), axis=1, norm='ortho')

# Apply IDCT to the transformed image
idct_img = idct(idct(dct_img, axis=0, norm='ortho'), axis=1, norm='ortho')

# Plot the original image
plt.subplot(1, 2, 1)
plt.imshow(dct_img, cmap='gray')
plt.title('Original Image')

# Plot the reconstructed image
plt.subplot(1, 2, 2)
plt.imshow(idct_img, cmap='gray')
plt.title('Reconstructed Image')

plt.show()
