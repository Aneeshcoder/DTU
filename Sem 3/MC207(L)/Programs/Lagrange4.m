function [] = Lagrange4() %Function Name
syms x y z p q dx dy c1 c2 

lhs = (x^2-y^2-z^2)*p + (2*x*y)*q; %LHS Side
rhs = 2*x*z; %RHS Side

C=coeffs(lhs,[q p]); %Coefficients of equation
P=C(1); %Extracting value of P
Q=C(2); %Extracting value of Q
R=rhs; %Extracting value of R

%int() is an integrating function 
%1st and 2nd expression
P=P*x/z; 
Q=Q*x/z; 
U = int(P,y) == int(Q,x) + c1 %Solving for U
S = int(P,y) - int(Q,x); %Solution for final ans

%1st and last expression
P=y^2*z/P; 
R=y^2*z/R; 
V = int(P,x) == int(R,z) + c2 %Solving for V
T = int(P,x) - int(R,z); %Solution for final ans

%Final display f(U,V) = 0
disp("Solution is given as f(U,V): ")
disp('f(')
disp(S)
disp(' , ')
disp(T)
disp(') == 0')
