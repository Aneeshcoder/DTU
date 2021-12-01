syms  x k t T B Bn C C1 C2 Ux lambda

%INCLUDE FUNCTION 
%e_value is the p term which is equal to root(lambda) 
[e_value, e_function] = sturm_liouville()
e_value = sqrt(e_value);

%SOLUTION
sol1 = subs(e_function,lambda,e_value)

%we can also use dsolve for this 
sol = int(1/T,T)==int(-e_value*e_value*k,t);
sol2 = C*solve(sol,T)
sol1 = subs(sol1,C1,0)

Ux = sol1*sol2;
Ux = subs(Ux,-C*C2,Bn)
%Bn is half range fourier sine series