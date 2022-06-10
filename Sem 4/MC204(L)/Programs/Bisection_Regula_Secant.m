%{
Program-2
Write a program to find the root of the equation, correct upto 2 decimal by
the following methods:
(i) Bisection Method
(ii) Regula Falsi Method
(iii) Secant Method

f(x)= x^2 - 6*x*exp(-x); 
Initial Interval [1.4,1.5]

f(x)= x^3 - x -1; 
Initial Interval [1,2]
%}

syms x f(x)

f(x) = input('\nInput equation: ');
cs = input('\n1. Bisection Method\n2. Regula Falsi Method\n3. Secant Method\n4. Newton Raphson Method\nEnter a num: ');
a = input('\nInput value of a: ');
b = input('Input value of b: ');
fprintf('\n');
root = 1/0;
n=2;
x(n)=b;
x(n-1)=a;
switch cs
    case 1
        %Bisection Method
        while true
            x0 = (a+b)/2;
            if (root-x0<0.001 && x0-root<0.001)
                fprintf('x0 = %f\tf(x0) = %f\n',x0,f(x0));
                root = x0;
                break;
            end
            root = x0;
            if f(x0)*f(a)<0
                fprintf('x0 = %f\tf(x0) = %f\n',x0,f(x0));
                b=x0;
            elseif f(x0)*f(b)<0
                fprintf('x0 = %f\tf(x0) = %f\n',x0,f(x0));
                a=x0;
            else
                if f(a)==0
                    root = a; 
                elseif f(b)==0
                    root = b;
                else 
                    root = x0;
                end
            end
        end
   
    case 2
        %Regula Falsi Method
        while true
            x0 = (a*f(b)-b*f(a))/(f(b)-f(a));
            if (root-x0<0.001 && x0-root<0.001)
                fprintf('x0 = %f\tf(x0) = %f\n',x0,f(x0));
                root = x0;
                break;
            end
            root = x0;
            if f(x0)*f(a)<0
                fprintf('x0 = %f\tf(x0) = %f\n',x0,f(x0));
                b=x0;
            elseif f(x0)*f(b)<0
                fprintf('x0 = %f\tf(x0) = %f\n',x0,f(x0));
                a=x0;
            else
                if f(a)==0
                    root = a; 
                elseif f(b)==0
                    root = b;
                else 
                    root = x0;
                end
            end
        end
        
    case 3
        %Secant Method
        while true
            x0 = (x(n-1)*f(x(n))-x(n)*f(x(n-1)))/(f(x(n))-f(x(n-1)));
            if (root-x0<0.001 && x0-root<0.001)
                fprintf('x0 = %f\tf(x0) = %f\n',x0,f(x0));
                root = x0;
                break;
            end
            fprintf('x0 = %f\tf(x0) = %f\n',x0,f(x0));
            root = x0;
            x(n-1)=x(n);
            x(n)=x0;
        end
        
    case 4
        %Newton Raphson Method
        while true
            fd = diff(f);
            x(n) = x(n-1) - (f(x(n-1))/fd(x(n-1)));
            if (root-x(n)<0.001 && x(n)-root<0.001)
                fprintf('xn = %f\tf(xn) = %f\n',x(n),f(x(n)));
                root = x(n);
                break;
            end
            fprintf('xn = %f\tf(xn) = %f\n',x(n),f(x(n)));
            root = x(n);
            x(n-1)=x(n);
        end
        
end
fprintf('\nSolution is: %f\n\n',root);