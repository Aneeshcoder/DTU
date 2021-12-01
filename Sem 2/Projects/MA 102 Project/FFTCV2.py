import cv2
from matplotlib import pyplot as plt
import numpy as np
x = np.arange(256)
y = np.sin(2*np.pi*x/10)
y += max(y)
img = np.array([[y[j]*127 for j in range(256)]for i in range(256)], 
 dtype = np.uint8)
plt.imshow(img)

f = np.fft.fft2(img)
fshift = np.fft.fftshift(f)
magnitude_spectrum = 20*np.log(np.abs(fshift))
plt.subplot(121)
plt.imshow(img.astype('uint8'))
plt.title('Input Image')
plt.subplot(122)
plt.imshow(magnitude_spectrum.astype('uint8'))
plt.title('FFT Image')
plt.show
