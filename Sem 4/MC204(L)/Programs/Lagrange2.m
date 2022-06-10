X = [0;1;2;5];
Y = [2;3;12;147];
xfind = 3;
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

p = [1 1 -1 2];
fprintf('Value using polynomial is %.2f\n\n',polyval(p,xfind));

fprintf('Error is %.2f\n\n',polyval(p,xfind)-yfinal);