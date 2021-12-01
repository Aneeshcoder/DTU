function[sols,vals]=Linear_DE_SYSTEM_SOLVERS(A,B,C)
syms t lambda

A = [3 1 -1;1 3 -1;3 3 -1];
B = [pi/2];
C = [0,1,0];

%A = [-3 -1;2 -1];
%B = [pi/2];
%C = [0,1];

n = length(A);
[V,D] = eig(A);
eigenvalues = diag(D)
const = reshape(sym('c%d',[1 n]),n,1);
unique_eigenvalues = unique(eigenvalues);
mults = histc(eigenvalues,unique_eigenvalues);
sols = sym('x%d',[1 n]);
if length(unique_eigenvalues) ~= length(eigenvalues)
    %For repeating eigenvalues
    i = 1;
    ch_mat = A-lambda*eye(n);
    
    %variable precision arithmetic
    V = vpa(V); 
    while i<=n
        [pos] = find(unique_eigenvalues == eigenvalues(i));
        if mults(pos)>1
            e_vector = V(:,i);
            a_mat = subs(ch_mat,eigenvalues(i));
            for j=1:mults(pos)
                V(:,i) = V(:,i).*(t^(j-1));
                P = inv(a_mat^(j-1))*e_vector;
                V(:,i) = V(:,i)+P;
                i = i+1;
            end
        else
            i = i+1;
        end
    end
end

for i=1:n
    sols(i)=(V(i,:)*exp(eigenvalues.*t))*const(i);
end
vals=vpasolve(subs(sols,t,B)==C);
constnames=fieldnames(vals);

% The final solution is
for i=1:n
    sols=subs(sols,const(i),vals.(constnames{i}));
end