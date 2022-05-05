%% Cap 5. Audiometría
% Vamos la comparar la función que desarrollamos por el método de potencias
% con SVD para calcular PCA

% Primero importamos los datos
samples = csvread('..\AudiometricData.csv', 1,2);

% Calculamos la matriz de covarianza
S = cov(samples);

%% Metodo SVD
% Calculamos PCA por el metodo SVD

n = size(S, 1);
[A, L, U] = svd( S' * S / (n-1) )

%% Método de potencias
% Calculamos PCA por el metodo de potencias

[u, l] = FuncPM(S)