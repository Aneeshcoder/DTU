X = [0;1;3;6];
Y = [18;10;-18;90];
xfind = 2;
yfinal = 0;
for i=1:4
    yint =1;
    for j=1:4
        if j==i
            continue
        end
        yint = yint*(xfind-X(j))/(X(i)-X(j));
    end
    yfinal = yfinal + yint*Y(i);
end
fprintf('\nValue using Lagrange Interpolation is %.2f\n\n',yfinal);

p = [2 -10 0 18];
fprintf('Value using polynomial is %.2f\n\n',polyval(p,xfind));

fprintf('Error is %.2f\n\n',polyval(p,xfind)-yfinal);