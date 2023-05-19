%Lagrange Method
%{
((x^3)/3) - ((3*y^2)/2) + 2*x
x - y == 0
%}

syms x y z lambda z1 z2 z3
m = input("Ïnput Number of variables: ");
func = input("Input Objective Function: ");
n = input("Ïnput Number of constraints: ");
cons(1) = input("Ïnput constraint: ");
if n>1
    for i=2:n
        cons(i) = input("Ïnput constraint: ");
    end
end
L = func + lambda*lhs(cons);
if m==2
    var = [x,y];
    cz = [z1,z2];
    dx = diff(L,x) == 0;
    dy = diff(L,y) == 0;
    dl = diff(L,lambda) == 0;
    sys = [dx;dy;dl];
    [xval,yval,lval] = solve(sys,[x y lambda],'Real',true);
    res = vpa([xval,yval,lval],5);
    sol = vpa([xval,yval],5)
    eqn = cz*transpose(jacobian(lhs(cons),var))==0;
    zsol(1) = 1;
    zsol(2) = subs(solve(eqn,z2),z1,zsol(1));
elseif m==3
    var = [x,y,z];
    cz = [z1,z2,z3];
    dx = diff(L,x) == 0;
    dy = diff(L,y) == 0;
    dz = diff(L,z) == 0;
    dl = diff(L,lambda) == 0;
    sys = [dx;dy;dz;dl];
    [xval,yval,zval,lval] = solve(sys,[x y z lambda],'Real',true);
    res = vpa([xval,yval,zval,lval],5);
    sol = vpa([xval,yval,zval],5)
    eqn = cz*transpose(jacobian(lhs(cons),var))==0;
    zsol(1) = 1;
    eqn = subs(eqn,z1,zsol(1));
    [zsol(2),zsol(3)] = solve(eqn,[z2,z3],'Real',true);
else
    var = x;
    cz = z1;
    dx = diff(L,x) == 0;
    dl = diff(L,lambda) == 0;
    sys = [dx;dl];
    [xval,lval] = solve(sys,[x lambda],'Real',true);
    res = vpa([xval,lval],5);
    sol = vpa(xval,5)
    eqn = cz*transpose(jacobian(lhs(cons),var))==0;
    zsol(1) = solve(eqn,z1);
end
HL = Hessian(func,m);
Val = zsol*HL*transpose(zsol);
for i=1:size(res,1)
    if subs(Val,var,sol(i,:))>0
        fprintf('\nLocal Minimum Point\n');
        sol(i,:)
        val = subs(func,var,sol(i,:))
        fprintf('\n');
    elseif subs(Val,var,sol(i,:))<0
        fprintf('\nLocal Maximum Point\n');
        sol(i,:)
        val = subs(func,var,sol(i,:))
        fprintf('\n');
    else
        res(i)
        fprintf('\nCant Determine\n\n');
    end
end










