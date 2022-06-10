%{
Program -1 (Example : 2)
Sin x + x^2 -1=0
%}

%Initializing variables
syms x

%Initial Equation
fx = sin(x)+x^2-1;
fprintf("\n Initial equation f(x) is: ");
disp(fx);

%Different equations x=phi(x)
eq(1)= (1-sin(x))^(1/2);
eq(2)= asin(1-x^2);

%Initial Approxiamation
x0=0.5;
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
    if (xn(a)-xn(a+1)<0.001 && xn(a+1)-xn(a)<0.001)
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