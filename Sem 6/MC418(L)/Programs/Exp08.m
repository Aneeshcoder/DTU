%{
% Define the optimization problem 
syms x y lambda theta mu gamma delta 
f = -x^2 - y^2; 
g = [x + y - 1, x^2 + y^2 - 1]; 
  
% Find the Lagrange Dual 
L = f + lambda'*g'; 
LD = simplify(-minimize(-L)); 
disp(['Lagrange Dual: ', char(LD)]); 
  
% Find the Mixed Dual 
M = f + theta*g' + mu*(g.^2)'; 
MD = simplify(-minimize(-M)); 
disp(['Mixed Dual: ', char(MD)]); 
  
% Find the Wolfe Dual 
W = f + gamma'*g' + 0.5*(g.^2)*delta';

f = -x^2 - y^2; 
g = [x + y - 1, x^2 + y^2 - 1]; 

%}

%Lagrange, Mixed, Wolfe Dual
clear
syms x y lambda1 lambda2 theta mu gamma delta 
f = input("Input Objective Function: ");
cons(1) = input("Input constraint 1: ");
cons(2) = input("Input constraint 2: ");
g = lhs(cons);

% Find the Lagrange Dual 
lambda = [lambda1; lambda2];
L = f + lambda(1)*g(1) + lambda(2)*g(2);
LD = simplify(-L); 
disp(['Lagrange Dual: ', char(LD)]);

% Find the Mixed Dual 
M = f + theta*g' + mu*(g.^2)';
MD = simplify(-M); 
disp(['Mixed Dual: ', char(MD)]);

% Find the Wolfe Dual 
W = f + gamma'*g' + 0.5*(g.^2)*delta; 
WD = simplify(-W); 
disp(['Wolfe Dual: ', char(WD)]);
