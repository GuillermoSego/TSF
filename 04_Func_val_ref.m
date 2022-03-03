%% Ejemplo paso por valor/referencia
% Tenemos la siguiente matriz
matrix = [1,2,3,4];

%%
% Paso por valor
AddConstant0(matrix, 3);

%%
% No le pasa nada porque es una copia
matrix
%%
% Paso por referencia
matrix = AddConstant (matrix, 3);
%%
% Modificas los valores originales
matrix
