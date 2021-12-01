function [] = Lagrange2() %Function Name
syms x y p q dx dy c1 c2 sol z(y) a b

lhs=(y^2)*p+((-1)*x*y)*q; %LHS Side
rhs=x*(z-2*y); %RHS Side

C=coeffs(lhs,[q p]); %Coefficients of equation
P=C(1); %Extracting value of P
Q=C(2); %Extracting value of Q
R=rhs; %Extracting value of R

%int() is an integrating function 
%1st and 2nd expression
P=P*2/y; 
Q=Q*2/y;
U = int(P,y) == int(Q,x) + c1; %Solving for U
S = int(P,y) - int(Q,x);

%2nd and last expression
Q=Q*y/(2*x);
R=R/x;
dz=dy*R/Q;
disp('dz/dy == ')
%also called q
disp(dz/dy)
cond = z(0) == 0;
sol = dsolve(diff(z,y)==dz/dy,cond);
V = (-1)*y*(z - simplify(sol));

disp("Solution is given as f(U,V): ")
disp('f(')
disp(S)
disp(', ')
disp(V)
disp(') == 0')