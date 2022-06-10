%{
%Nearest Neighbour Interpolation
A = zeros(3,3);
A(:)=[10,2,9,4,18,14,22,7,25];
C = imresize(A,[6,6],'nearest');

X = A';
X = X(:)';
Y = [1:1:9];
plot(Y,X,'-ob','MarkerFaceColor','b','lineWidth',1.5);

XN = C';
XN = XN(:)';
YN = [0.25:0.25:9];
hold all
plot(YN,XN,'.-r','lineWidth',1);
legend('Actual Data','Nearest Neighbour Interpolated Data')
%}


%{
%Linear Interpolation
A(:)=[10,2,9,4,18,14,22,7,25];
X = A';
X = X(:)';
Y = [1:1:9];
plot(Y,X,'.b','MarkerSize',15);

hold all
plot(Y,X,'.-r','lineWidth',1);
legend('Actual Data','Linear Interpolation')
%}




%Cubic Interpolation
x = -4:4;
y = [0 .15 1.12 2.36 2.36 1.46 .49 .06 0];
cs = spline(x,[0 y 0]);
xx = linspace(-4,4,101);
plot(x,y,'.b','MarkerSize',15);

hold all
plot(xx,ppval(cs,xx),'-r');
legend('Actual Data','Cubic Interpolation')
