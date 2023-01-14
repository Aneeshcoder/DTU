%{
------------------------
%Unrestricted Random Walk
%------------------------
fprintf("\n--------------------------\n");
fprintf("Unrestricted Random Walk");
fprintf("\n--------------------------\n\n");
p = input("Probability of +1 step: ");
q = input("Probability of -1 step: ");
k = input("Position: ");
n = input("No. of Instances/ Steps: ");
if p+q == 1
    c = 1;
else
    c = 0.5;
end
mean = p-q;
std_dev = sqrt(p+q-(p-q)^2);
up_lim = (k+c-n*mean)/(std_dev*sqrt(n));
low_lim = (k-c-n*mean)/(std_dev*sqrt(n));
probability = normcdf(up_lim) - normcdf(low_lim)

%--------------------
%2 Absorbing Barriers
%--------------------
fprintf("\n--------------------------\n");
fprintf("2 Absorbing Barriers");
fprintf("\n--------------------------\n\n");
p = input("Probability of +1 step: ");
q = input("Probability of -1 step: ");
a = input("Position of 1st(+ve) barrier: ");
b = input("Position of 2st(-ve) barrier: ");
if b <0
    b = -b;
end
if p == q
    prob_a = b/(a+b);
else
    prob_a = (p^a)*((p^b - q^b)/(p^(a+b) - q^(a+b)));
end
Probability_absorb_a = prob_a
Probability_absorb_b = 1 - prob_a
%}
%---------------------
%2 Reflecting Barriers
%---------------------
fprintf("\n--------------------------\n");
fprintf("2 Reflecting Barriers");
fprintf("\n--------------------------\n\n");
p = input("Probability of +1 step: ");
q = input("Probability of -1 step: ");
a = input("Position of reflecting barrier: ");
if p==q
    pi(1) = 1/(a+1);
else
    pi(1) = (1-(p/q))/(1-(p/q)^(a+1));
end
for i=1:100
    k = (a*i)/100;
    pi(i+1) = pi(1)*(p/q)^k;
end
plot(0:a/100:a,pi);
title("2 Reflecting Barriers");
xlabel("Position of Particle");
ylabel("Probability Distribution");
