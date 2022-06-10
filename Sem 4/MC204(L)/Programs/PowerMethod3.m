A = [1,-3,2;4,4,-1;6,3,5];
X = [1;0;0];
EigValold = 0;
err = 0.001;

while true
   X = A*X;
   EigValnew = max(abs(X));
   if EigValnew-EigValold<err
        if EigValold-EigValnew<err
             break
        end
   end
   EigValold = EigValnew;
   X = X/EigValnew;
end

MaxEigValue = EigValnew
MaxEigVect = X/EigValnew
a = max(eig(A))