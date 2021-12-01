#Creating FFT image
import numpy as np
import cv2
from matplotlib import pyplot as plt
img = cv2.imread('/Cristiano_Ronaldo_2018.jpg',0)
dft = cv2.dft(np.float32(img),flags = cv2.DFT_COMPLEX_OUTPUT)
dft_shift = np.fft.fftshift(dft)
magnitude_spectrum = 20*np.log(cv2.magnitude(dft_shift[:,:,0],dft_shift[:,:,1]))
plt.subplot(121)
plt.imshow(img, cmap = 'gray')
plt.title('Input Image')
plt.subplot(122)
plt.imshow(magnitude_spectrum, cmap = 'gray')
plt.title('Magnitude Spectrum')
plt.show()

#Creating a circular mask for Magnitude Spectrum
rows, cols = img.shape
crow,ccol = rows/2 , cols/2
mask = np.zeros((rows,cols,2),np.uint8)
r = 30
center = [crow,ccol]
x, y = np.ogrid[:rows,:cols]
mask_area = (x-center[0])**2 + (y-center[1])**2 <= r*r
mask[mask_area] = 1

# Using FFT to get back to original image with filter applied
fshift = dft_shift*mask
fshiftmask = 20*np.log(cv2.magnitude(fshift[:,:,0],fshift[:,:,1]))
f_ishift = np.fft.ifftshift(fshift)
img_back = cv2.idft(f_ishift)
img_back = cv2.magnitude(img_back[:,:,0],img_back[:,:,1])
plt.subplot(121),plt.imshow(fshiftmask, cmap = 'gray')
plt.title('Input Image'), plt.xticks([]), plt.yticks([])
plt.subplot(122),plt.imshow(img_back, cmap = 'gray')
plt.title('Magnitude Spectrum'), plt.xticks([]), plt.yticks([])
plt.show()
