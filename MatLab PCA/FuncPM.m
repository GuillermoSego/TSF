% Esta funcion hace el metodo de potencias y regresa una matriz U
function [U, l] = FuncPM(S)

    % El numero de veces que se hara el ciclo
    times = size(S);
    times = times(1,1);

    % Error
    e = 1*10e-8;
    i = 1;
    
    % Reservamos la memoria
    U = zeros(times);
    v = zeros(times);
    l = zeros(1, times);

    while(i<times + 1 )
        
        % La primera aproximación St es U*S
        St = sum( S )';
        t = ones( size(St) );

        % Calculamos las t
        while(1)

            nt = St/max(St);

            if (t - nt) < e
                break;
            end

            t = nt;
            St = S*t;
        end
        
        % Calculamos las U, las v y las l
        U(:,i) = t/norm(t);
        v(:,i) = sqrt(max(St)) * U(:,i);
        l(i) = max(St);  

        % Redefinimos la matriz de cov
        S = S - v(:,i)*v(:,i)';

        % Contamos
        i = i + 1;

    end

end