clear
syms x y(x)

%Linear Differential Equations
%y' +2y = sin(x)
%y(0) = 0
eqn1 = diff(y,x) + 2*y - sin(x) == 0;
initcond = y(0)==0;
sol1 = dsolve(eqn1,initcond)

%y'' + xy' + y = 0
%y(0) = 0, y'(0) = 0
eqn2 = diff(y,x,2) + x*diff(y,x) + y == 0;
ny = diff(y,x);
cond = [y(0)==1, ny(0)==0];
sol2 = dsolve(eqn2,cond)

%Non Linear Differential Equations 
%(y' + y)^2 = 1
%y(0) = 0
eqn3 = (diff(y,x) + y)^2 ==1;
sol3 = dsolve(eqn3,initcond)

%Non Linear Simultaneous Differential Equations using dsolve
syms t a(t) b(t)
eqn41 = 2*diff(a) - 2*diff(b) - 3*a == t;
eqn42 = 2*diff(a) + 2*diff(b) + 3*a + 8*b == 2;
eqn4 = [eqn41,eqn42];
condn = [a(0)==1, b(0)==0];
sol4 = dsolve(eqn4,condn);
sol4a = sol4.a
sol4b = sol4.b

%Non Linear Simultaneous Differential Equations using ode45
f = @(t,Y)[Y(1)-Y(1)*Y(2);Y(1)*Y(2)-Y(2)];
[tsol,ysol] = ode45(f,[0:0.1:40],[5,6]);
plot(tsol,ysol)
xlabel("Time (t)")
ylabel("Population")
legend("Prey (x)","Predator (y)")