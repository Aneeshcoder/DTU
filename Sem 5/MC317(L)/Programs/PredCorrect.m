clear
syms f(x,y)

f(x,y) = 2*x*(y-1);
x0 = 0;
y0 = 0;

%Actual Function
func = 1 - exp(x^2);

b = 0.4;
a = 0;
h = (b-a)/4;
err = 0.000000005;

%Values using 4th order RK Method
ysol(1) = y0;
xsol(1) = x0;
fun(1) = f(xsol(1),ysol(1));
for i = 1:4
    k1 = vpa(h*f(xsol(i),ysol(i)));
    k2 = vpa(h*f(xsol(i)+(h/2),ysol(i)+(k1/2)));
    k3 = vpa(h*f(xsol(i)+(h/2),ysol(i)+(k2/2)));
    k4 = vpa(h*f(xsol(i)+h,ysol(i)+k3));
    k = (1/6)*(k1+2*(k2+k3)+k4);
    ysol(i+1) = ysol(i)+k;
    xsol(i+1) = x0 + i*h;
    fun(i) = f(xsol(i),ysol(i));
end

%Predictor
ysol(5) = ysol(1) + ((4*h)/3)*(2*fun(4) - fun(3) + 2*fun(2));
Predicted_Value = vpa(ysol(5))

%Corrector
yc(1) = ysol(5);
fc(1) = f(xsol(5),ysol(5));
i = 1;
while true
    yc(i+1) = ysol(3) + (h/3)*(fc(i) + 4*fun(4) + fun(3));
    fc(i+1) = f(xsol(5),yc(i+1));
    if(yc(i+1)-yc(i) < err)
        if(yc(i)-yc(i+1) < err)
            break
        end
    end
    i = i+1;
end

Corrected_Value = vpa(yc(i+1))
Number_of_Corrections = i
Actual_Value = vpa(subs(func,x,xsol(5)))