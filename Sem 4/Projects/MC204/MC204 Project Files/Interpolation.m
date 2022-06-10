I=imread('CR.jpg');
I=double(I(:,:,1));

[m n]= size(I);
[x,y] = meshgrid(1:n, 1:m);

%Scaling
r=2.5;
[p,q]=meshgrid(1:r:n, 1:r:m); 

%Interpolation 'linear','nearest','bilinear','bicubic','spline'
I2= interp2(x,y,I,p,q,'spline');

figure
subplot(1,2,1),imagesc(I),axis image
title('Original','FontSize',18)
subplot(1,2,2),imagesc(I2),axis image
title('Cubic Spline interpolator','FontSize',18)
colormap(gray)

print -djpeg CR_BS.jpg