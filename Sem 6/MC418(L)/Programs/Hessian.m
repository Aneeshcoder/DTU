%Hessian Function
function Hessian_Matrix = Hessian(f,n)
    syms x y z
    if n==2
        Hessian_Matrix = [diff(f,x,2), diff(diff(f,x),y); diff(diff(f,y),x), diff(f,y,2)];
    elseif n==3
        Hessian_Matrix = [diff(f,x,2), diff(diff(f,x),y), diff(diff(f,x),z); diff(diff(f,y),x), diff(f,y,2), diff(diff(f,y),z); diff(diff(f,z),x), diff(diff(f,z),y), diff(f,z,2)];
    else
        Hessian_Matrix = diff(f,x,2);
    end
end