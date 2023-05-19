%The NLPP under consideration is f = x^2 
% subject to -1 <= x <= 1 

%Barrier Function Method
clear
syms x alpha;
f = input("Input Objective Function: ");
cons(1) = input("Input constraint 1: ");
cons(2) = input("Input constraint 2: ");
r_val(1) = lhs(cons(1));
r_val(2) = rhs(cons(2));
g(1) = 1/(r_val(1)-x); 
g(2) = 1/(x-r_val(2)); 
b = -g(1)-g(2);
C = f + alpha*b; 

sol = limit(solve(diff(C,x) == 0),alpha,0);
for i=1:length(r_val)
    sol = sol(sol~=r_val(i));
end
x_val = sol
fval = subs(f,sol) 
