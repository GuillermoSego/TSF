%%

S = [ 102.74,  88.67, 67.04, 54.06
   88.67, 142.74, 86.56, 80.03
   67.04,  86.56, 84.57, 69.42
   54.06,  80.03, 69.42, 99.06 ];

%% Escalamos la matriz
Mscale = (S  - mean(S) );

%% Método de PCA
n = size(Mscale, 1);
[A, L, U] = svd( S );

%% Porcentajes de variabilidad 
% Dividimos los eigenvalores por la traza de la matriz diagonal L

diag(L)/trace(L)

%% Sección 2.4


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

%% Añadimos un vector lienalmente dependiente x1 + x2
samples = [samples , sum(samples, 2)];

%% Centramos en la media
samples = samples - mean(samples);

%% Aplicamos PCA
n = size(samples, 1);
[A, L, U] = svd(samples)


