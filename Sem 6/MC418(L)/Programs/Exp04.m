%KKT Conditions
%{
x + y - x^2 + 2*x*y - 2*y^2
2*x + y
%}

syms x y z
m = input("Ïnput Number of variables: ");
maxeqn = input("Input Max Objective Function: ");
n = input("Ïnput Number of constraints: ");
consLHS(1) = input("Ïnput constraint LHS: ");
consRHS(1) = input("Ïnput constraint RHS: ");
for i=2:n
    consLHS(i) = input("Ïnput constraint RHS: ");
    consRHS(i) = input("Ïnput constraint RHS: ");
end
if m==2
    var = [x,y];
    z = [0,0];
elseif m==3
    var = [x,y,z];
    z = [0,0,0];
else
    var = x;
    z = 0;
end
J = jacobian(maxeqn,var)
D = (1/2)*jacobian(J,var)
C = transpose(subs(J,var,z))
A = jacobian(consLHS,var)
b = transpose(consRHS)
fprintf("KKT Conditions are:\n");
KKTLHS = [-2*D, transpose(A), -eye(ndims(D(1))), zeros(ndims(D(1)),size(A,1)); A, zeros(size(A,1)), zeros(size(A,1),ndims(D(1))), eye(size(A,1))]
KKTRHS = [C; b]