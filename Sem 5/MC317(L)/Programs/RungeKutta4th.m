clear
syms f(x,y) func(x)

%f(x,y)=-y*y;
% x0=0 y0=1
f(x,y) = -y*y;
x0 = 0;
y0 = 1;

func(x) = 1/(x+1);

n = 100;
b = 10;
a = 0;
h = (b-a)/n;

ysol(1) = y0;
xsol(1) = x0;
yactual(1) = y0;
for i=1:n
    k1=vpa(h*f(xsol(i),ysol(i)));
    k2=vpa(h*f(xsol(i)+(h/2),ysol(i)+(k1/2)));
    k3=vpa(h*f(xsol(i)+(h/2),ysol(i)+(k2/2)));
    k4=vpa(h*f(xsol(i)+h,ysol(i)+k3));
    k=(1/6)*(k1+2*(k2+k3)+k4);
    ysol(i+1)=ysol(i)+k;
    xsol(i+1) = x0 + i*h;
    yactual(i+1) = func(xsol(i+1));
end

%Root Mean Square Error
diff = (ysol-yactual).^2;
RMSE_RK4 = sqrt(mean(diff))

figure
fplot(func,'b');
hold on
plot(xsol,ysol,'--r');
xlim([0 10])
title("Runge Kutta Order 4")
xlabel("x")
ylabel("y(x)")
legend("Actual Value","Predicted Value")
hold off