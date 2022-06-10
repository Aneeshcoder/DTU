syms f(x,y)
f(x,y)=(y^2-x^2)/(y^2+x^2);

% x1=0 y1=1 h=0.2
% y(0.2)
fprintf("\n\nFOR y(0.2)")
x0=0;
y0=1;
h=0.2;
k1=vpa(h*f(x0,y0))
k2=vpa(h*f(x0+h/2,y0+k1/2))
k3=vpa(h*f(x0+h/2,y0+k2/2))
k4=vpa(h*f(x0+h,y0+k3))
k=(1/6)*(k1+2*k2+2*k3+k4)
y1=y0+k;
fprintf("Approximate value of y(0.2) is %f",y1);

% x1=0.2 y1=1.196 h=0.2
% y(0.4)
fprintf("\n\nFOR y(0.4)")
x1=0.2;
k1=vpa(h*f(x1,y1))
k2=vpa(h*f(x1+h/2,y1+k1/2))
k3=vpa(h*f(x1+h/2,y1+k2/2))
k4=vpa(h*f(x1+h,y1+k3))
k=(1/6)*(k1+2*k2+2*k3+k4)
y2=y1+k;
fprintf("\n\nApproximate value of y(0.4) is %f\n\n",y2);