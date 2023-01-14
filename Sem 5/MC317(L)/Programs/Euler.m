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
    xsol(i+1) = x0 + i*h;
    ysol(i+1) = ysol(i) + h*f(xsol(i),ysol(i));
    yactual(i+1) = func(xsol(i+1));
end

%Root Mean Square Error
diff = (ysol-yactual).^2;
RMSE_Euler = sqrt(mean(diff))

figure
fplot(func,'b');
hold on
plot(xsol,ysol,'--r');
xlim([0 10])
title("Euler's Method")
xlabel("x")
ylabel("y(x)")
legend("Actual Value","Predicted Value")
hold off