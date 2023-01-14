%Poisson Process
clear

%Homogeneous Poisson Process
syms f(n)
lambda = input("Arrival Rate: ");
m = input("No. of Trials: ");
time = input("Time: ");
f(n) = (exp(-lambda*time)*((lambda*time)^n))/factorial(n);
probs(1) = vpa(f(0));
prob(1) = vpa(f(0));
for i=0:m-1
    probs(i+2) = probs(i+1) + vpa(f(i+1));
    prob(i+2) = vpa(f(i+1));
end
prob_k_Arrivals = prob(m+1)
prob_atmost_k_Arrivals = probs(m+1)
plot(0:m,prob);
title("Homogeneous Poisson Distribution");
xlabel("No. of trials (n)");
ylabel("Probability");

%{
Non Homogeneous Poisson Process
syms t ip(t) g(n) lambda_func(t)
ip = input("Arrival Rate function: ");
m = input("No. of Trials: ");
time = input("Time: ");
lambda_func(t) = int(ip,t,0,t);
g(n) = subs((exp(-lambda_func)*((lambda_func)^n))/factorial(n),t,time);
probs(1) = vpa(g(0));
for i=0:m-1
    probs(i+2) = vpa(g(i+1));
end
Prob_k_arrival = probs(m+1)
%}