%Input the objective functions and constraints
%{
m = 2;
func = (y - 5)/(-x - y + 9);
n = 5;
cons(1) = -2*x - 5*y <= -10;
cons(2) = 4*x + 3*y <= 20;
cons(3) = -x + y <= 2;
cons(4) = -x <= 0;
cons(5) = -y <= 0;
%}

%{
m = 2;
func = (2*x + 3*y)/(x + y + 7);
n = 5;
cons(1) = 3*x + 5*y <= 15;
cons(2) = 4*x + 3*y <= 12;
cons(3) = y - x <= 3;
cons(4) = -x <= 0;
cons(5) = -y <= 0;
%}

%{
m = 2;
func = (2*x + 3*y)/(x + y + 7);
n = 4;
cons(1) = 3*x + 5*y <= 15;
cons(2) = 4*x + 3*y <= 12;
cons(3) = -x <= 0;
cons(4) = -y <= 0;
%}

%{
m = 2;
func = x/(x + y + 1);
n = 4;
cons(1) = x + 2*y <= 1;
cons(2) = x + y <= 1;
cons(3) = -x <= 0;
cons(4) = -y <= 0;
%}

%Charnes and Cooper Method
clear
syms x y w a b

m = input("Input Number of variables: ");
func = input("Input Max Objective Function: ");
n = input("Input Number of constraints: ");
cons(1) = input("Input constraint: ");
for i=2:n
    cons(i) = input("Input constraint: ");
end

%Declaration of Variable arrays
oldvar = [x y];
newvar = [a/w b/w];
vari = [a b w];

%Checking the condition for Num and Deno Values
[num,deno] = numden(func)
if subs(num,oldvar,[0 0])>0
    num = -num;
    deno = -deno;
end

%Forward substitution for the given problem
nfunc = subs(func,deno,1/w)
ncons = subs(cons,oldvar,newvar);
nfunc = simplify(subs(nfunc,oldvar,newvar))
n = n+1;
ncons(n) = subs(deno*w,oldvar,newvar)==1

%Getting the LHS and RHS coefficient values from the constraints
consLHS(1) = lhs(ncons(1));
consRHS(1) = rhs(ncons(1));
for i=2:n
    consLHS(i) = lhs(ncons(i));
    consRHS(i) = rhs(ncons(i));
end

%Solving the construted problem using simplex method,
A = zeros(n-1,m+1);
b = zeros(1,n-1);
Aeq = zeros(1,m+1);
Beq = 1;
for i=1:n-1
    A(i,1) = subs(diff(consLHS(i),vari(1)),vari(m+1),1);
    A(i,2) = subs(diff(consLHS(i),vari(2)),vari(m+1),1);
    A(i,3) = -consRHS(i);
end
consLHS(n) = simplify(consLHS(n));
for i=1:m+1
    f(1,i) = diff(nfunc,vari(i));
    Aeq(1,i) = diff(consLHS(n),vari(i));
end

%LinProg Inbuilt function
f = -double(f)
A = double(A)
b = double(b)
Aeq = double(Aeq)
Beq = double(Beq)
xsol = linprog(f,A,b,Aeq,Beq)

%Reverse substitution for getting the final value
final_sol(1) = xsol(1)/xsol(m+1);
for i=2:m
    final_sol(i) = xsol(i)/xsol(m+1);
end
final_sol
objective_func_val = vpa(subs(func,oldvar,final_sol),2)

