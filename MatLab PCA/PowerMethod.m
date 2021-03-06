%% Metodo de potencias
% The power Method

samples = [
10.0, 10.7;
10.4, 9.8;
9.7, 10.0;
9.7, 10.1;
11.7, 11.5;
11.0, 10.8;
8.7, 8.8;
9.5, 9.3;
10.1, 9.4;
9.6, 9.6;
10.5, 10.4;
9.2, 9.0;
11.3, 11.6;
10.1, 9.8;
8.5, 9.2;
    
];

S = cov(samples)

%%
% La primera aproximación St es U*S

St = sum( S )';

t = ones( size(St) );


%%
e = 1*10e-8;

while(1)

    nt = St/max(St);

    if (t - nt) < e
        fprintf("Valor del indice: %d\n", i);
        break;
    end

    t = nt;
    St = S*t;
end

fprintf("La t calculada");
t

%% Calculamos las u
U = t/norm(t)

%% Calculamos V
v = sqrt(max(St)) * U;

%% Repetimos
% Ahora hacemos el mismo procedimiento pero con una nueva matriz de
% covarianza

Snew = S - v*v';

St = sum( Snew )';

t = ones( size(St) );

while(1)

    nt = St/max(St);

    if (t - nt) < e
        fprintf("Valor del indice: %d\n", i);
        break;
    end

    v = [0,]

    t = nt;
    St = Snew*t;
end

fprintf("La t calculada");
t

%% Calculamos las u
U = t/norm(t)

%% Calculamos V
v = sqrt(max(St)) * U;

%% Implementacion del metodo en una funcion
% Primero, llamamos una funcion
% [U, l] = FuncPM(S)
