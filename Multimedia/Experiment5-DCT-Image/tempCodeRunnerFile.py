
# Apply DCT to the imqage
dct_img = dct(dct(img, axis=0, norm='ortho'), axis=1, norm='ortho')

# Apply IDCT to the transformed image
idct_img = idct(idct(dct_img, axis=0, norm='ortho'), axis=1, norm='ortho')

# Plot the original image
plt.subplot(1, 2, 1)
plt.imshow(img, cmap='gray')
plt.title('Original Image')

# Plot the reconstructed image
plt.subplot(1, 2, 2)
plt.imshow(idct_img, cmap='gray')
plt.title('Reconstructed Image')