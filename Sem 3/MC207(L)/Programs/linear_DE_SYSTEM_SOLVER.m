function[sols] = linear_DE_SYSTEM_SOLVER(A)
syms t lambda

A = [3 1;-2 1]
%A = [3 4;0 4]; %L1 ~= L2
%A = [2 0;0 2]; %L1 = L2
%A = [8 12 -2;-3 -4 1;-1 -2 2]; %L1 = L2 = L3
%A = [7 -1 6;-10 4 -12;-2 1 -1]; %L1 ~= L2 ~= L3
%A = [0 1 1;1 0 1;1 1 0]; %L1 = L2 ~= L3

n = length(A);
[V,D] = eig(A);
eigenvalues = diag(D)
consts = reshape(sym('c%d',[1 n]),n,1);
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
    sols(i) = (V(i,:).*exp(eigenvalues'*i))*consts;
end