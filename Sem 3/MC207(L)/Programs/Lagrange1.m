function [] = Lagrange1() %Function Name
syms x y z p q dx dy c1 c2 

lhs = (tan(x)*p + tan(y)*q); %LHS Side
rhs = tan(z); %RHS Side

C=coeffs(lhs,[q p]); %Coefficients of equation
P=C(1); %Extracting value of P
Q=C(2); %Extracting value of Q
R=rhs; %Extracting value of R

%int() is an integrating function 
%1st and 2nd expression
P=1/P; 
Q=1/Q; 
U = int(P,x) == int(Q,y) + c1; %Solving for U
S = int(P,x) - int(Q,y);
S = simplify(exp(S));

%2nd and last expression
Q=Q; 
R=1/R; 
V = int(Q,y) == int(R,z) + c2; %Solving for V
T = int(Q,y) - int(R,z);
T = simplify(exp(T));

disp("Solution is given as f(U,V): ")
disp('f(')
disp(S)
disp(', ')
disp(T)
disp(') == 0')