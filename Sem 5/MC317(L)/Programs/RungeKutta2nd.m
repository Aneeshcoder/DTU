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
    k2=vpa(h*f(xsol(i)+((2*h)/3),ysol(i)+((2*k1)/3)));
    k=(1/4)*(k1+3*k2);
    ysol(i+1)=ysol(i)+k;
    xsol(i+1) = x0 + i*h;
    yactual(i+1) = func(xsol(i+1));
end

%Root Mean Square Error
diff = (ysol-yactual).^2;
RMSE_RK2 = sqrt(mean(diff))

figure
fplot(func,'b');
hold on
plot(xsol,ysol,'--r');
xlim([0 10])
title("Runge Kutta Order 2")
xlabel("x")
ylabel("y(x)")
legend("Actual Value","Predicted Value")
hold off