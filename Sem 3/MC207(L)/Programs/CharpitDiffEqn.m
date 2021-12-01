%Function Name
function [] = CharpitDiffEqn() 

% f = ((p*p)+(q*q))*y = q*z
% Declaring syms type varibles
syms x y z p q dx dy c1 c2 a b c

lhs = ((p*p)+(q*q))*y;
rhs = q*z;

% Given equation
f = lhs - rhs

% Finding partial derivatives
fx = diff(f,x);
fy = diff(f,y);
fz = diff(f,z);
fp = diff(f,p);
fq = diff(f,q);

% denominator of dp, dq, dz
f1 = fx + p* fz
f2 = fy + q * fz
f3 = simplify(-p*fp-q*fq)

% Solving for given condition
if f2==0 %condtion for q=constant
    Q = a
    eqn = subs(f, q, Q);
    eq2 = solve(eqn, p);
    P = eq2

elseif f1==0 %condtion for p=constant
    P = a
    eqn = subs(f, p, P);
    eq2 = solve(eqn, q);
    Q = eq2

else
    int1 = 2*f1/p;
    int2 = 2*f2/p;
    intsol = int(int2,p)-int(int1,q)-c*c;
    P1 = solve(intsol,p);
    eqn = subs(f,p,P1);
    eqn2 = solve(eqn,q);
    Q = eqn2
    eqn3 = subs(intsol,q,Q);
    eqn4 = solve(eqn3,p);
    P = eqn4
    
end

% Solution after Integration
sol = int(Q,y)+int(P,x);

disp("Solution is given as f(x,y)= ")
disp(sol)