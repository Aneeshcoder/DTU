%Function Name
function [] = HomoPDE_sincos() 
syms D d f1 f2 f3 y x z m c

%D is wrt x and d is wrt y
%We take f1 and f2 inplace of phi1 and phi2

%F is LHS and f is RHS
F = (D*D - 5*D*d + 4*d*d)*z; 
f = sin(2*x+3*y);

%Substitute D with m and d with 1
eqn = subs(subs(F, D, m), d, 1);

%Values of m as a 3*1 or 2*1 matrix
mval = solve(eqn, m)

%Find CF
if mval(1)~=mval(2)
    CF = f1*(y+mval(1)*x) + f2*(y+mval(2)*x)
else
    CF = f1*(y+mval(1)*x) + x*f2*(y+mval(2)*x)
end
    
%Find coeff of x and y
%sin(x) = sin(pi - x)
eqnx = pi - asin(simplify(subs(subs(f,y,0),x,1)))
eqny = pi - asin(simplify(subs(subs(f,x,0),y,1)))

%Find PI
PIF = F/z;
PI_deno = subs(subs(subs(PIF,D*D,(-1)*eqnx*eqnx) ,D*d,(-1)*eqnx*eqny) ,d*d,(-1)*eqny*eqny)
PI = f/PI_deno

%Final answer
final_ans = CF + PI