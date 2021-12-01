%Function Name
function [] = CharpitDE2() 

% f = z - p*x - q*y - p*p - q*q
% Declaring syms type varibles
syms x y z p q dx dy c1 c2 a b

lhs = z;
rhs = p*x + q*y + p*p + q*q;

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
end

% Solution after Integration
sol=int(Q,y)+int(P,x);

disp("Solution is given as f(x,y)= ")
disp(sol)