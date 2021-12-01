function [] = Lagrange3() %Function Name
syms x y z p q dx dy c1 c2 sol deno num sol

lhs = (x^2-y^2-z^2)*p + (2*x*y)*q; %LHS Side
rhs = 2*x*z; %RHS Side

C = coeffs(lhs,[q p]); %Coefficients of equation
P=C(1); %Extracting value of P
Q=C(2); %Extracting value of Q
R=rhs; %Extracting value of R

%int() is an integrating function 
%2nd and 3rd expression
Q=2*x/Q; 
R=2*x/R; 
V = int(Q,y) == int(R,z) + c2; %Solving for V
T = exp(int(Q,y) - int(R,z));
T = simplify(T);

%3rd and last expression
R=1/R;
Q=1/Q;
P=P/2;
deno = 2*(P + y*Q + z*R);
num = 2/3*(int(x/deno,x) + int(y/deno,y) +int(z/deno,z));
U = num == int(1/R,z) +c1;
sol = exp(num - int(1/R,z));
sol = simplify(sol);

disp("Solution is given as f(U,V)=0: ")
disp('f(')
disp(sol)
disp(', ')
disp(T)
disp(') == 0')