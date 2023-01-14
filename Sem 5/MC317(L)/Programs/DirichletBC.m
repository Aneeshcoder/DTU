syms u(x) a(x) b(x) f(x) p(i) q(i) r(i)
eqn = diff(u,x,2) + (x^2 + 1)*diff(u,x) + u*sin(x) == exp(x);
a(x) = x^2 + 1;
b(x) = sin(x);
f(x) = exp(x);

%Dirichlet Boundary Conditions
%u(0) = 0 and u(1) = 1
h = 0.1;
xa = 0;
xb = 1;
n = (xb-xa)/h;
ua = 0;
ub = 1;
TriMat = eye(n-1);
CoeffMat(1) = 1;
r(i) = (1/(h^2)) - (a(i)/(2*h));
p(i) = b(i) - (2/(h^2));
q(i) = (1/(h^2)) + (a(i)/(2*h));
for j=1:n-1
    if j == 1
        TriMat(j,1) = p(j);
        TriMat(j,2) = q(j);
        CoeffMat(j) = f(j) - r(j)*ua;
    elseif j == n-1
        TriMat(j,n-2) = r(j);
        TriMat(j,n-1) = p(j);
        CoeffMat(j) = f(j) - q(j)*ub;
    else
        TriMat(j,j) = p(j);
        TriMat(j,j+1) = q(j);
        TriMat(j,j-1) = r(j);
        CoeffMat(j) = f(j);
    end    
end
Coefficient_Matrix = CoeffMat'
Tri_Diagonal_Matrix = TriMat
Solution_values = (inv(TriMat)*CoeffMat')