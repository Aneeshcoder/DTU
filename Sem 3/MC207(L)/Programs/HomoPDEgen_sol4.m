%Function Name
function [] = HomoPDEgen_sol4() 

%t is any random variable 
syms D d f1(t) f2(t) f3(t) y x z m c

%D is wrt x and d is wrt y
%We take f1, f2 and f3 inplace of phi_1, phi_2 and phi_3

%F is LHS and f is RHS
F = (D^2 +  2*D*d + d^2)*z; 
f = 2*cos(y) -x*sin(y);

%Making the constant of D to 1
Fconst = subs(subs(subs(F,D,1),z,1),d,0);
F = F/Fconst;
f = f/Fconst;

%Substitute D with m and d with 1
eqn = subs(subs(F, D, m), d, 1);

%Values of m as a 3*1 or 2*1 matrix
mval = solve(eqn, m)
n = numel(mval);

%Find CF
if n==2
    if mval(1)~=mval(2)
        CF = f1(y+mval(1)*x) + f2(y+mval(2)*x)
    else
        CF = f1(y+mval(1)*x) + x*f2(y+mval(2)*x)
    end
    
elseif n==3
    if mval(1)~=mval(2)~=mval(3)
        CF = f1(y+mval(1)*x) + f2(y+mval(2)*x) + f3(y+mval(3)*x)
    elseif mval(1) == mval(2) ~= mval(3)
        CF = f1(y+mval(1)*x) + x*f2(y+mval(2)*x) + f3(y+mval(3)*x)
    elseif mval(1) ~= mval(2) == mval(3)
        CF = f1(y+mval(1)*x) + x*f2(y+mval(2)*x) + f3(y+mval(3)*x)
    elseif mval(1) == mval(3) ~= mval(2)
        CF = x*f1(y+mval(1)*x) + f2(y+mval(2)*x) + f3(y+mval(3)*x)
    else
        CF = f1(y+mval(1)*x) + x*f2(y+mval(2)*x) + x*x*f3(y+mval(3)*x)
    end
end

%Find PI
PIn = f;
while n>0
    PIn = subs(PIn,y,c-mval(n)*x);
    PIn = int(PIn,x);
    Value_m = mval(n)
    PIn = subs(PIn,c,y+mval(n)*x)
    n = n-1;
end

%Final Particular Integral
PI = simplify(PIn)

%Final answer
final_ans = CF + PI