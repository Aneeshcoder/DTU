syms x k c t f(x) g(x) X(x) T(t) A B Bn C D C1 C2 lambda

%INCLUDE FUNCTION FOR DISTANCE
[e_value, e_function] = sturm_liouville();
e_value = sqrt(e_value);

%SOLUTION FOR X
sol_X = simplify(subs(e_function,lambda^(1/2),k));

%INCLUDE FUNCTION FOR TIME
[e_value2, e_function2] = sturm_liouville();
e_value2 = sqrt(e_value2);

%SOLUTION FOR T
sol_T = subs(subs(e_function,x,t),lambda^(1/2),k*c);

X(x) = subs(subs(sol_X,C1,A),-C2,B)
T(t) = subs(subs(sol_T,C1,C),-C2,D)

%Applying Boundary condition and Initial condition
%Bn is half range fourier sine series
X(x) = subs(subs(X(x),A,0),B,Bn)

%f(x) and g(x) are half range fourier sine series
T(t) = subs(subs(T(t),C,f(x)),D,g(x))
