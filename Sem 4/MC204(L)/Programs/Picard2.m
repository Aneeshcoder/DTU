syms x y ysol 

diff = 2 - (y/x);
ysol(1) = 2;
x0 = 1;
xfind = 1.2;

for i=1:3
    ysol(i+1) = ysol(1) + int(subs(diff,y,ysol(i)),x0,x);
    Iteration_equation = simplify(ysol(i+1))
    fprintf("Value at %d iteration is %f\n\n",i,subs(ysol(i+1),x,xfind));
end
