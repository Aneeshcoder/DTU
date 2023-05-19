%Convex Optimization Problem
%{ 
4*x + 3*y
x+y-4
x*y-1
-x
-y
%}

syms x y z
m = input("Ïnput Number of variables: ");
obj = input("Input Objective Function: ");
n = input("Ïnput Number of constraints: ");
const(1) = input("Ïnput constraint: ");
for i=2:n
    const(i) = input("Ïnput constraint: ");
end
objval = Convex(obj,0,0,0,m);
count = 0;
for i=1:n
    count = count + Convex(const(i),0,0,0,m);
end
if objval==1 && count==-n
    fprintf('\nIt is Convex Programming Problem\n\n');
elseif objval==-1 && count==n
    fprintf('\nIt is Convex Programming Problem\n\n');
elseif objval==1 && count==n
    fprintf('\nIt is Convex Programming Problem\n\n');
elseif objval==-1 && count==-n
    fprintf('\nIt is Convex Programming Problem\n\n');
else
    fprintf('\nIt is NOT Convex Programming Problem\n\n');
end