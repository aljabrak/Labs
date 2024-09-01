function [x, n] = regula_falsi_method(f, a, b, iter)

p = [];
n = 0;
if polyval(f, a) * polyval(f, b) < 0
    for i = 1 : iter
        n = n + 1 ;
        p = (a * polyval(f, b) - b * polyval(f, a)) / (polyval(f, b) - polyval(f, a));
        
        if polyval(f, a) * polyval(f, p) < 0
            b = p;
        
        elseif polyval(f, b) * polyval(f, p) < 0
            a = p;
        
        elseif round(polyval(f, a) * polyval(f, b)) == 0
            break
                   
        end
    end
    x = p;
else
    x = "Error";
end

end
