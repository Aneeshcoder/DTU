%{
13*x1 + 5*x2  - 3*x3 + x4 = 18
2*x1 + 12*x2 + x3  - 4*x4 = 13
x1 - 4*x2 + 10*x3 + x4 = 29
2*x1 + x2 - 3*x3 + 9*x4 = 31
%}
syms x1 x2 x3 x4

opr = input('1. Gauss Seidel Method\n2. Jacobi Method\nChoice: ');
eqn1 = 13*x1 + 5*x2  - 3*x3 + x4 == 18;
eqn2 = 2*x1 + 12*x2 + x3  - 4*x4 == 13;
eqn3 = x1 - 4*x2 + 10*x3 + x4 == 29;
eqn4 = 2*x1 + x2 - 3*x3 + 9*x4 == 31;

n1 = solve(eqn1,x1)
n2 = solve(eqn2,x2)
n3 = solve(eqn3,x3)
n4 = solve(eqn4,x4)

Xold = [0;0;0;0];
X = [0;0;0;0];
err(1:4,1) = 0.001;

switch opr
    case 1
        %Gauss Seidal method
        steps=0;
        while true
            X(1) = subs(subs(subs(n1,x2,X(2)),x3,X(3)),x4,X(4));
            X(2) = subs(subs(subs(n2,x1,X(1)),x3,X(3)),x4,X(4));
            X(3) = subs(subs(subs(n3,x1,X(1)),x2,X(2)),x4,X(4));
            X(4) = subs(subs(subs(n4,x1,X(1)),x3,X(3)),x2,X(2));
            steps = steps+1;
            if X-Xold<err
                if Xold-X<err
                    break
                end
            end
            Xold=X;
        end
        
    case 2
        %Jacobi method
        steps=0;
        while true
            X(1) = subs(subs(subs(n1,x2,Xold(2)),x3,Xold(3)),x4,Xold(4));
            X(2) = subs(subs(subs(n2,x1,Xold(1)),x3,Xold(3)),x4,Xold(4));
            X(3) = subs(subs(subs(n3,x1,Xold(1)),x2,Xold(2)),x4,Xold(4));
            X(4) = subs(subs(subs(n4,x1,Xold(1)),x3,Xold(3)),x2,Xold(2));
            steps = steps+1;
            if X-Xold<err
                if Xold-X<err
                    break
                end
            end
            Xold=X;
        end
end
X
steps