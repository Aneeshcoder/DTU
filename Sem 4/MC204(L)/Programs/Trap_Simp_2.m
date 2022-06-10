syms x f(x)
opt = input('1. Trapezoidal Rule\n2. Simpsons 1/3 Rule\nChoice:');
f(x) = exp(x^2);
a = 0;
b = 2;
n = 10;
h = (b-a)/n;

i = 0;
sum = 0;
switch opt
    case 1
        while i<=n
            if i==0 || i==n
                sum = sum + f(a+i*h);
            else
                sum = sum + 2*f(a+i*h);
            end
            i = i+1;
        end
        int = h*sum/2;
    
    case 2
        while i<=n
            if i==0 || i==n
                sum = sum + f(a+i*h);
            elseif rem(i,2)==1
                sum = sum + 4*f(a+i*h);
            else
                sum = sum + 2*f(a+i*h);
            end
            i = i+1;
        end
        int = h*sum/3;
end

fprintf('\nValue of Integral is %f\n\n',int);