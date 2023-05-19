%Hessian Matrix
%4*x^2 + y^2 + 4*x*y

syms x y
f = input('Function to check f(x,y): '); 
Hessian_Matrix = [diff(f,x,2), diff(diff(f,x),y); diff(diff(f,y),x), diff(f,y,2)];
EigenValues = eig(Hessian_Matrix);
x0 = input('Convexity to check at x: ');
y0 = input('Convexity to check at y: ');
EigenValues = subs(subs(EigenValues,x,x0),y,y0);

if (EigenValues(1)==0 && EigenValues(2)>0) || (EigenValues(2)==0 && EigenValues(1)>0)
    fprintf('\nFunction is Convex Function\n\n');
elseif (EigenValues(1)==0 && EigenValues(2)<0) || (EigenValues(2)==0 && EigenValues(1)<0)
    fprintf('\nFunction is Concave Function\n\n');
elseif (EigenValues(1)>0 && EigenValues(2)>0) || (EigenValues(2)>0 && EigenValues(1)>0)
    fprintf('\nFunction is Strictly Convex Function\n\n');
elseif (EigenValues(1)<0 && EigenValues(2)<0) || (EigenValues(2)<0 && EigenValues(1)<0)
    fprintf('\nFunction is Strictly Concave Function\n\n');
else
    fprintf('\nCant Determine\n\n');
end