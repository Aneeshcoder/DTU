Ts = 1/50;
t = 0:Ts:10-Ts; 
a = sin(2*pi*15*t) + sin(2*pi*20*t);
plot(t,a)

Ts = 1/50;
t = 0:Ts:10-Ts; 
a = sin(2*pi*15*t) + sin(2*pi*20*t);
y = fft(a); 
fs = 1/Ts;
f = (0:length(y)-1)*fs/length(y);
n = length(a); 
fshift = (-n/2:n/2-1)*(fs/n);
yshift = fftshift(y);
plot(fshift,abs(yshift))
