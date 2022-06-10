syms f(x,y)
f(x,y)=x+y;

% x0=0 y0=1 h=0.2
% y(0.2)
x0=0;
y0=1;
h=0.2;
k1=vpa(h*f(x0,y0))
k2=vpa(h*f(x0+h/2,y0+k1/2))
k3=vpa(h*f(x0+h/2,y0+k2/2))
k4=vpa(h*f(x0+h,y0+k3))
k=(1/6)*(k1+2*k2+2*k3+k4)
y1=y0+k;
fprintf("\nApproximate value of y(0.2) is %f\n\n",y1);