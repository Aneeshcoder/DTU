syms x y ysol 

diff = y + exp(x);
ysol(1) = 0;
x0 = 0;
xfind = 1;

for i=1:4
    ysol(i+1) = ysol(1) + int(subs(diff,y,ysol(i)),x0,x);
    Iteration_equation = simplify(ysol(i+1))
    fprintf("Value at %d iteration is %f\n\n",i,subs(ysol(i+1),x,xfind));
end
