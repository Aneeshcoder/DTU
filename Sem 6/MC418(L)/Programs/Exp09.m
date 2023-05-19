%The NLPP under consideration is f = x2 
% subject to x >= 1 

clc

%Penalty Function Method
clear
syms x alpha; 
f = input("Input Objective Function: ");
cons = input("Input Constraints: ");
cond = input("Less than (1) or, Greater than (-1): ");
r_val = lhs(cons);
if(cond == 1) 
    %Case for less than constraint
    p = 0; 
    u = f + alpha*p; 
    sol = solve(diff(u,x)==0);
    sol = limit(sol,alpha,inf);
    %Condition for less than 
    if(sol<r_val) 
        x_val = sol
        obj_func_val = subs(f,sol)
    else 
        return; 
    end 
else 
    %Case for greater than constraint
    p = subs(f,x,r_val-x);
    u = f + alpha*p;
    sol = solve(diff(u,x) == 0); 
    sol = limit(sol,alpha,inf);
    %Condition for greater than
    if(sol<r_val)
        return; 
    else
        x_val = sol
        obj_func_val = subs(f,sol)
    end 
end 