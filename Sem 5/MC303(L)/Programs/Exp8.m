n = input("No. of Renewals: ");

%Normally distributed with mean & standard deviation
fprintf("\n--------------------------\n");
fprintf("Normal Distribution");
fprintf("\n--------------------------\n\n");

u = input("Mean: ");
std_dev = input("Standard Deviation: ");
Expected_wait_time = n*u

%Exponentially Distributed with lambda
fprintf("\n--------------------------\n");
fprintf("Exponentially Distribution");
fprintf("\n--------------------------\n\n");

lambda = input("Lambda: ");
Expected_wait_time = n/lambda