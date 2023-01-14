%Number of hours in a day
x = [1:1:24]';

%Discrete Time Discrete State Space
%Number of sales of pen from a shop in a day
y = 5 + randi([0 50],24,1);
figure
scatter(x,y,'bo');
hold on
stairs(x,y,'r--');
xlabel('Time (hr)');
ylabel('Number of sales of pen');
title('Discrete Time Discrete State Space');

%Discrete Time Continuous State Space
%Time required to sell 5 pen in each hour of day
y = rand(24,1) + randi([1 59],24,1);
figure
scatter(x,y,'bo');
hold on
plot(x,y,'r--');
xlabel('Time (hr)');
ylabel('Time required to sell 5 pen (minutes)');
title('Discrete Time Continuous State Space');