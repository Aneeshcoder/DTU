YourImage=imread('CR.jpg');
scale = 1/10;
r = size(YourImage,1);
c = size(YourImage,2);
[R, C] = ndgrid(1:r, 1:c);
newrv = linspace(1, r, floor(r*scale));
newcv = linspace(1, c, floor(r*scale));
[NewR, NewC] = ndgrid(newrv, newcv);
for channel = size(YourImage,3) : -1 : 1
  newImage(:,:,channel) = interp2(R, C, YourImage(:,:,channel), NewR, NewC, 'spline');
end
newImage = cast(newImage, class(YourImage));
imshow(newImage)