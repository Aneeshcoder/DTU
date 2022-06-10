%x f(x) DI DII DIII DIV

x = [0;1;2;3;4];
y = [1;1.5;2.2;3.1;4.6];
FDT = zeros(length(x),length(x)+1);
FDT(:,1) = x;
FDT(:,2) = y;

BDT = zeros(length(x),length(x)+1);
BDT(:,1) = x;
BDT(:,2) = y;

i = length(x)-1;
j = 3;
while j<=length(x)+1
    for i = 1:length(x)+2-j
        FDT(i,j) = FDT(i+1,j-1)-FDT(i,j-1);
        BDT(length(x)+1-i,j) = BDT(length(x)+1-i,j-1)-BDT(length(x)-i,j-1);
    end
    j=j+1;
end

fprintf('\nForward Difference Table:\n');
fprintf('x\t   f(x)\t\tDI\t\tDII\t\tDIII\tDIV\n');
for i=1:length(x)
    fprintf('%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n',FDT(i,1),FDT(i,2),FDT(i,3),FDT(i,4),FDT(i,5),FDT(i,6));
end

fprintf('\n\nBackward Difference Table:\n');
fprintf('x\t   f(x)\t\tDI\t\tDII\t\tDIII\tDIV\n');
for i=1:length(x)
    fprintf('%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n',BDT(i,1),BDT(i,2),BDT(i,3),BDT(i,4),BDT(i,5),BDT(i,6));
end
fprintf('\n\n')