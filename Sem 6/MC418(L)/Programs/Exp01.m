%Convex Function
%1 2 x*x

syms x f(x)
x1 = input('Lower Limit: '); 
x2 = input('Upper Limit: '); 
f(x) = input('Function to check f(x): '); 
flag = 0;
for i=0:0.01:1
    if f((1-i)*x1 + i*x2) > (1-i)*f(x1) + i*f(x2)
        fprintf('\nFunction is not Convex Function\n\n')
        flag = -1;
        break;
    end
end
if flag == 0
    fprintf('\nFunction is Convex Function\n\n')
end