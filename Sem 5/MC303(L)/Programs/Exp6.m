clear
%Unrestricted Random Walk
p = input("Probability of +1 step: ");
q = input("Probability of -1 step: ");
j = input("Lower Limit: ");
k = input("Upper Limit: ");
n = input("No. of Instances/ Steps: ");
if p+q == 1
    c = 1;
else
    c = 0.5;
end
mean = p-q;
std_dev = sqrt(p+q-(p-q)^2);
up_lim = (k+c-n*mean)/(std_dev*sqrt(n));
low_lim = (j-c-n*mean)/(std_dev*sqrt(n));
probability = normcdf(up_lim) - normcdf(low_lim)