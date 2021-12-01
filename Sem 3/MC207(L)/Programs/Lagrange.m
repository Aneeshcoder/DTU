function [] = Lagrange() %Function Name
syms x y z p q dx dy c1 c2 

lhs=((y^2)*z/x)*p+(x*z)*q; %LHS Side
rhs=(y^2); %RHS Side

C=coeffs(lhs,[q p]); %Coefficients of equation
P=C(1); %Extracting value of P
Q=C(2); %Extracting value of Q
R=rhs; %Extracting value of R

%int() is an integrating function 
%1st and 2nd expression
P=P*x/z; 
Q=Q*x/z; 
U = int(P,y) == int(Q,x) + c1; %Solving for U
S = int(P,y) - int(Q,x);
S = simplify(S);

%1st and last expression
P=y^2*z/P; 
R=y^2*z/R; 
V = int(P,x) == int(R,z) + c2; %Solving for V
T = int(P,x) - int(R,z);
T = simplify(T);

disp("Solution is given as f(U,V): ")
disp('f(')
disp(S)
disp(', ')
disp(T)
disp(') == 0')