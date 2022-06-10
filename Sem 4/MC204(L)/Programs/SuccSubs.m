%{
Program - 1 (Example : 1)
Write a program to find the real roots of x^3 - 2x - 8 = 0 using 
the method of successive substitution, correct upto 2 places of decimal.
%}

%Initializing variables
syms x

%Initial Equation
fx = x^3-2*x-8;
fprintf("\n Initial equation f(x) is: ");
disp(fx);

%Different equations x=phi(x)
eq(1)= x^3-x-8;
eq(2)= (x^3-8)/2;
eq(3)= (2*x+8)^(1/3);

%Initial Approxiamations
x0=2.5;
fprintf("\n Initial Value x0: %f\n\n", x0);

%Finding perfect fit equation for the required problem
for i=1:length(eq)
    d=diff(eq(i),x);
    d=subs(d,x,x0);
    if d<1 && d>-1
        break;
    end
end

%Printing satisfied equation
fprintf("\n Satisfying phi(x) is: ");
disp(eq(i));

%Finding Solution and saving them in an array
xn(1)=x0;
a=1;
while a>0
    xn(a+1)=subs(eq(i),x,xn(a));
    if (xn(a)-xn(a+1)<0.001)
        break;
    end
    a=a+1;
end

%Printing solution of each step
for i=1:a+1
    fprintf("\n Iteration %d value of x is: %f\n",i,xn(i));
end

%Printing Final Solution
fprintf("\n Root is: %f\n\n", xn(a+1));