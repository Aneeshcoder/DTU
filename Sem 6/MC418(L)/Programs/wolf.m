function [x,fval]=wolf(D,l,b,Mat,inq,minimize)
n = length(l);
m = length(b);
if ~isequal(size(Mat,1),m) || ~isequal(length(inq),m) || ~isequal(size(D,1),...
        size(D,2)) || ~isequal(size(D,1),n) || ~isequal(size(Mat,2),n)
    fprintf('\nError: Dimension mismatch!\n');
    return
end
if nargin < 4 || nargin > 6
    fprintf('\nError:Number of input arguments are inappropriate!\n');
    return
end
if nargin < 5
    minimize = 0;
    inq = -ones(m,1);
elseif nargin < 6
    minimize = 0;
end
if minimize == 1
    l = -l;
    D = -D;
end
if min(eig(-D)) < 0 % Checking convexity of Hessian
    fprintf('\nError: Wolf method may not converge to global optimum!\n');
    return
elseif (min(eig(-D)) == 0) && ~isempty(find(l,1))
    fprintf('\nError: Wolf method may not converge to global optimum!\n');
    return
end
count = n;
for i = 1 : m
    if (inq(i) > 0)
        Mat(i,:) = -Mat(i,:);
        b(i) = -b(i);
    elseif (inq(i) == 0)
        count = count + 1;
        Mat(i,count) = -1;
        l(count) = 0;
        D(count,count) = 0;
    end
end
a = [-2*D Mat' -eye(count,count) zeros(count,m);Mat zeros(m,m + count) eye(m,m)];
d = [l;b];
for i = 1 : count + m
    if(d(i) < 0)
        d(i) = -d(i);
        a(i,:) = -a(i,:);
    end
end
cb = zeros(1,count + m);
bv = zeros(1,count + m);
nbv = (1 : 2 * (count + m));
c = zeros(1,2 * (count + m));
rem = zeros(1,count + m);
for i = 1 : count + m
    if(a(i,count + m + i) == -1)
        bv(i) = 2 * (count + m) + i;
        cb(i) = -1;
    elseif(a(i,count + m + i) == 1)
        rem(i)=count + m + i;
        bv(i) = count + m + i;
        cb(i) = 0;
    end
end
[h,j,k] = find(rem);
a(:,k) = [];
c(k) = [];
nbv(k) = [];
r = cb * a - c;
exitflg = 0;
iter = 0;
z = cb * d;
[w,y] = size(a);
opt = 0;
while(exitflg == 0)
    iter = iter + 1;
    r_new = r;
    found = 0;
    while found == 0
        [u,v] = min(r_new);
        leave = 0;
        if ~(u < 0)
            if abs(z) > 10^-6
                fprintf('\nError: Wolf method fails to find optimum!\n');
                exitflg = 1;
                found = 1;
            else
                fprintf('\nThe optimum has achieved!\n');
                exitflg = 1; opt = 1;
                found = 1;
            end
        else
            ratio = bitshift(1,30);
            check = 0;
            for i = 1 : w
                if bv(i) <= 2 * (count +  m) && abs(bv(i) - nbv(v)) == count + m
                    check = 1;
                end
            end
            if check == 0
                for i = 1 : w
                    if a(i,v) > 0 && (d(i) / a(i,v)) < ratio
                        ratio = d(i) / a(i,v);
                        leave = i;
                    end
                end
                for i = 1 : w
                    for j = 1 : y
                        if i ~= leave && j ~= v
                            a(i,j) = a(i,j) - a(i,v) * a(leave,j) / a(leave,v);
                        end
                    end
                end
                z = z - d(leave) * r(v) / a(leave,v);
                for j = 1 : y
                    if j ~= v
                        r(j) = r(j) - r(v) * a(leave,j) / a(leave,v);
                        a(leave,j) = a(leave,j) / a(leave,v);
                    end
                end
                for i = 1 : w
                    if i ~= leave
                        d(i) = d(i) - a(i,v) * d(leave) / a(leave,v);
                        a(i,v) = -a(i,v) / a(leave,v);
                    end
                end
                d(leave) = d(leave) / a(leave,v);
                a(leave,v) = 1 / a(leave,v);
                r(v) = -r(v) / a(leave,v);
                temp = nbv(v);
                nbv(v) = bv(leave);
                bv(leave) = temp;
                found = 1;
            elseif check == 1
                r_new(v) = 1;
            end
        end
    end    
end
if opt == 1
    x = zeros(n,1);
    for i = 1 : w
        if bv(i) <= n
            x(bv(i)) = d(i);
        end
    end
    fval = x'*l+x'*D*x;
    if minimize == 1
        fval = -fval;
    end
end
