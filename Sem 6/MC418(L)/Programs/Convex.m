%Convex Function if +1
function hess = Convex(f,x0,y0,z0,n)
    syms x y z
    if n==2
        var = [x,y];
        val = [x0,y0];
        Hessian_Matrix = [diff(f,x,2), diff(diff(f,x),y); diff(diff(f,y),x), diff(f,y,2)];
    elseif n==3
        var = [x,y,z];
        val = [x0,y0,z0];
        Hessian_Matrix = [diff(f,x,2), diff(diff(f,x),y), diff(diff(f,x),z); diff(diff(f,y),x), diff(f,y,2), diff(diff(f,y),z); diff(diff(f,z),x), diff(diff(f,z),y), diff(f,z,2)];
    else
        var = x;
        val = x0;
        Hessian_Matrix = diff(f,x,2);
    end
    hess = 0;
    EigenValues = eig(Hessian_Matrix);
    EigenValues = subs(EigenValues,var,val);
    for i=1:n
        if EigenValues(i)>=0
            hess = hess + 1;
        elseif EigenValues(i)<=0
            hess = hess - 1;
        end
    end
    if hess==n
        hess = 1;
    elseif hess==-n
        hess = -1;
    else
        hess = 0;
    end
end