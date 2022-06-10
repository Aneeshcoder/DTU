clear
clc
syms y(x)

%
%Linear Model
subplot(2,1,1)
ode = diff(y,x,2)==-0.01*diff(y,x) - 2.4*y + 1.2*sin(0.06*x);
Dy = diff(y,x);
ySol(x) = dsolve(ode,y(0)==1.2,Dy(0)==0);
ezplot(ySol(x))
hold on
diffeqn(x) = diff(ySol,x);
ezplot(diffeqn(x))
hold on
legend('y','v');
hold off
%}

%
%Non Linear Model
subplot(2,1,2)
InitCond = [1.2; 0];
tspan = [0 10];
[t, theta] = ode45(@(t,theta)[theta(2);-0.01*theta(2) - 1.2*sin(2*theta(1)) + 1.2*sin(0.06*t)], tspan, InitCond);
plot(t,theta)
hold on
legend('y','v');
hold off
%}