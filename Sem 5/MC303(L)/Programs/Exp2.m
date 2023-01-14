%Continuous Time Discrete State Space
%Population of a species at any specific point of time
x = [0:0.1:5];
y = randi([5 50],length(x),1);
figure
stairs(x,y);
ylim([0 55]);
title("Continuous Time Discrete State Space");
xlabel("Time");
ylabel("Population of species");

%Continuous Time Continuous State Space
%Waiting time for the train of passengers arriving (rate 5) at a platform
x = [0:0.1:10];
y = 5 + 5*rand(length(x),1);
figure
plot(x,y);
title("Continuous Time Continuous State Space");
xlabel("Time");
ylabel("Waiting Time of passengers");