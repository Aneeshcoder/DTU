%{
Program -4 
Write a program to find the solution of 4 X 4 system of linear equations by Gauss siedal iteration method and Jacobi Iteration method
*Example -1 *
10*x1 - 2*x2  - x3 - x4 = 3
-2*x1 + 10*x2 - x3  - x4 = 15
- x1 - x2 + 10*x3 - 2*x4 = 27
-x1 - x2 - 2*x3 + 10*x4 = -9
%}

syms x1 x2 x3 x4

opr = input('1. Gauss Seidel Method\n2. Jacobi Method\nChoice: ');
eqn1 = 10*x1-2*x2-x3-x4==3;
eqn2 = -2*x1+10*x2-x3-x4==15;
eqn3 = -x1-x2+10*x3-2*x4==27;
eqn4 = -x1-x2-2*x3+10*x4==-9;

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