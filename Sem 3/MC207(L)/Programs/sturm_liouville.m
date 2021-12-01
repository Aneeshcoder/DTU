function [e_value, e_function, non_zero] = sturm_liouville(L) 
syms y(x)
syms lambda n

%Equation is, y" + (lambda)y = 0

L = 1;
%L = pi/4;
%L = pi/2;

%sprintf stores the string in buffer
sprintf('Solving for various conditions...') 
sprintf('When lambda > 0') 
assume(lambda > 0);

%dsolve computes symbolic solutions to ordinary differential equations
%sol = diff(X,n) applies diff recursively n times, resulting in the nth difference
solution = dsolve(diff(y, 2) + lambda * y == 0); 
e_function = solution
diff_sol = diff(solution, x);

%subs(s) returns a copy of s , replacing symbolic variables in s , with their values obtained from the calling function
vals = solve(subs(diff_sol, x,0) == 0, subs(diff_sol, x,L) == 0);
non_zero = vals;
sprintf('Non-zero values in the solution')
vals;

%Eigen Value for this solution
e_value = [(n * pi) / L] .^ 2;

sprintf('When lambda = 0')
try
    solution = dsolve(subs(diff(y, 2) + lambda * y == 0), lambda, 0); 
catch
    sprintf('No non-trivial solution')
end

sprintf('When lambda < 0')
assume(lambda < 0);
solution = dsolve(diff(y, 2) + lambda * y == 0); 
diff_sol = diff(solution, x);

%No Explicit non trivial solution exists
vals = solve(subs(diff_sol, 0) == 0, subs(diff_sol, L) == 0);