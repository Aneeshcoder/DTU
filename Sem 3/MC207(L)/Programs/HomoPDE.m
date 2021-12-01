%Function Name
function [] = HomoPDE() 
syms D d x y z m f1 f2 f3

%D is wrt x and d is wrt y
%We take f1, f2 and f3 inplace of phi1, phi2 and phi3

%F is LHS and f is RHS
F = (D*D*D - 6*D*D*d + 11*D*d*d - 6*d*d*d)*z; 
f = exp(5*x + 6*y);

%Substitute D with m and d with 1
eqn1 = subs(F, D, m);
eqn2 = subs(eqn1, d, 1)

%Values of m as a 3*1 matrix
mval = solve(eqn2, m)

%Find CF
if mval(1)~=mval(2)~=mval(3)
    CF = f1*(y+mval(1)*x) + f2*(y+mval(2)*x) + f3*(y+mval(3)*x)
elseif mval(1) == mval(2) ~= mval(3)
    CF = f1*(y+mval(1)*x) + x*f2*(y+mval(2)*x) + f3*(y+mval(3)*x)
elseif mval(1) ~= mval(2) == mval(3)
    CF = f1*(y+mval(1)*x) + x*f2*(y+mval(2)*x) + f3*(y+mval(3)*x)
elseif mval(1) == mval(3) ~= mval(2)
    CF = x*f1*(y+mval(1)*x) + f2*(y+mval(2)*x) + f3*(y+mval(3)*x)
else
    CF = f1*(y+mval(1)*x) + x*f2*(y+mval(2)*x) + x*x*f3*(y+mval(3)*x)
end

%Find equation of variables D and d
F1 = F/z;
F2 = f;

%Find values of constants of x and y
fpi = log(f);
valx = diff(fpi,x)
valy = diff(fpi,y)

%Substitute values of x and y in F1
while true
    eqn3 = subs(F1,D,valx);
    eqn4 = subs(eqn3,d,valy);
    if eqn4~=0
        break
    else
        F1 = diff(F1,D);
        F2 = F2*x;
    end
end

%Find PI
PI = F2/eqn4

%Final answer
final_ans = CF+PI