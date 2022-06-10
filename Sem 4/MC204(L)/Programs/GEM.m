%{
Program - 3
Write a program to find the solution of 4 X 4 system of linear equations by Gauss- Elimination Method 
without Partial Pivoting and with Partial Pivoting

2*x1 + x2  - x3 + 2*x4 = 5
4*x1 + 5*x2 - 3*x3 + 6*x4 = 9
-2*x1 + 5*x2 - 2*x3 + 6x*4 = 4
4*x1 + 11*x2 - 4*x3 + 8*x4 = 2

x1 + 2*x2  - x3 + x4 = 6
-x1 + x2 + 2*x3 - x4 = 3
2*x1 - x2 + 2*x3 + 2*x4 = 14
x1 + x2 - x3 + 2*x4 = 8
%}
%A = [1 2 -1 1;-1 1 2 -1;2 -1 2 2;1 1 -1 2];
%b = [6;3;14;8];


A = [2 1 -1 2;4 5 -3 6;-2 5 -2 6;4 11 -4 8];
b = [5;9;4;2];

action = input('Whether you want to perform GEM:\n1. without Partial Pivoting\n2. with Partial Pivoting\nEnter a num: ');

Aug = A;
N = max(size(Aug));
Aug(:,N+1) = b

%Without Partial Pivoting
if action == 1
    for j=2:N 
        for i=j:N
            m = Aug(i,j-1)/Aug(j-1,j-1); 
            Aug(i,:) = Aug(i,:) - Aug(j-1,:)*m;  
        end 
    end
    
    %Display Augmented Matrix after ELementary Row Transf
    Aug
    
    x = zeros(N,1);
    x(N) = Aug(N,N+1)/Aug(N,N);
    %Backward subs
    for i=N-1:-1:1
        x(i) = (Aug(i,N+1)-Aug(i,i+1:N)*x(i+1:N))/Aug(i,i);
    end
    
%With Partial Pivoting
else
    %Performing Partial Pivoting
    for i =1:N-1
        maxel = max(Aug(:,i));
        for t =1:N
            if Aug(t,i)==maxel
                extra = Aug(t,:);
                Aug(t,:)=Aug(i,:);
                Aug(i,:)=extra;
                break;
            end
        end
        Aug
        for j=i+1:N
            m = Aug(j,i)/Aug(i,i); 
            Aug(j,:) = Aug(j,:) - Aug(i,:)*m;
        end
    end    
    
    %Display Augmented Matrix after ELementary Row Transf
    Aug
    
    x = zeros(N,1);
    x(N) = Aug(N,N+1)/Aug(N,N);
    for i=N-1:-1:1
        x(i) = (Aug(i,N+1)-Aug(i,i+1:N)*x(i+1:N))/Aug(i,i);
    end
end

%Display Value of x after GEM
x