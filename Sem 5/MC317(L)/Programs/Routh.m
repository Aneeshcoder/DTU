clear
%f = x^7 + 3*x^6 + 2*x^5 + 5*x^3 + 6*x^2 + 3*x+ 1;

syms x
f = input('Input the polynomial: ');
deg = polynomialDegree(f);
coeff(1) = subs(f,x,0);
diff_f = f;

%Obtain Coefficient array for polynomial
for i=1:deg
    diff_f = diff(diff_f,x)/i;
    coeff(i+1) = subs(diff_f,x,0);
end

%Putting a_0 +ve 
if coeff(deg+1)<0
    coeff = -coeff;
end

%Obtain Routh Hurwitz Matrix
coeff_matrix = zeros(deg);
r = 1; c = 1;
for i=1:2:2*deg-1
    for j=i:-1:0
        if c==deg+1
            break
        end
        if (deg+1-j)<=0
            coeff_matrix(c,r) = 0;
        else
            coeff_matrix(c,r) = coeff(deg+1-j);
        end
        c = c+1;
    end
    r = r+1;
    c = 1;
end
coeff_matrix

%Stability using Routh Hurwitz Criteria
if det(coeff_matrix)>0
    fprintf('Stable System\n\n');
else
    fprintf('Not stable System\n\n');
end