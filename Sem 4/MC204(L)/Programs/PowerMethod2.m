A = [15,-4,-3;-10,12,-6;-20,4,-2];
X = [1;1;1];
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