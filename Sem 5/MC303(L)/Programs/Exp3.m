
clear
%Bernoulli Process
n = input("Trials: ");
k = input("Successes: ");
p = input("Probability of Success: ");
q = 1-p;

%Out of n trials k are successes
%Probability of getting 5 boys out of 10 children
m = n; 
c = 1;
for i=1:k
    c = c*(m/i);
    m = m-1;
end
prob_k = vpa(c*(p^(k))*(q^(n-k)))

%kth success occur at nth trial
%Probability of getting 5th boy at 10th trial 
m = n-1; 
c = 1;
for i=1:k-1
    c = c*(m/i);
    m = m-1;
end
prob_kth = vpa(c*(p^(k-1))*(q^(n-k))*p)