clear
%Non Homogeneous Poisson Process
syms t ip(t) g(n) lambda_func(t)
ip = input("Arrival Rate function: ");
m = input("No. of Trials: ");
time = input("Time: ");
lambda_func(t) = int(ip,t,0,t);
g(n) = subs((exp(-lambda_func)*((lambda_func)^n))/factorial(n),t,time);
probs(1) = vpa(g(0));
prob(1) = vpa(g(0));
for i=0:m-1
    probs(i+2) = probs(i+1) + vpa(g(i+1));
    prob(i+2) = vpa(g(i+1));
end
prob_k_Arrivals = prob(m+1)
prob_less_than_k_Arrivals = probs(m+1)
plot(0:m,prob);
title("Non Homogeneous Poisson Distribution");
xlabel("No. of trials (n)");
ylabel("Probability");
