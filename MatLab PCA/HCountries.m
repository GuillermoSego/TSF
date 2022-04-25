%% Analisis de la comida que consumen algunos paises
% Vamos a desarrollar un analisis de PCA para un conjunto de paises

%% Guardamos los datos
M = csvread('..\PCA.csv', 1,2);

%% Escalamos la matriz
Mscale = (M  - mean(M) ) ./ (std( M ));

%% Método de PCA
n = size(Mscale, 1);
[A, L, U] = svd( Mscale' * Mscale / (n-1) );

%% Calculamos los scores
z1 = ( Mscale ) * A(:,1) ;
z2 = ( Mscale ) * A(:,2) ;

%% Graficas
% Ahora vamos a graficar los datos reduciendo la dimensionalidad 

plot(-z1, -z2, 'o'); 
title('Scores: Paises');
text(-z1, -z2, ["Germany", 'Italy', 'France', 'Holland', 'Belgium', 'Luxembourg', ...
    'England', 'Portugal', 'Austria', 'Switzerland', 'Sweden', 'Denmark', ...
    'Norway', 'Findland', 'Spain', 'Ireland'] );

yline(0);
xline(0);

%% 
% Grafica de los loadings
figure;
plot(-A(:,1), -A(:,2), 'o' );
title ('Loadings: Food');
text(-A(:,1), -A(:,2), ["Gr\_Coffe", 'Inst\_Coffe', 'Tea', 'Sweetner', ...
    'Biscuits', 'Pa\_Soup', 'Ti\_Soup', 'In\_Potat', 'Fro\_Fish', 'Fro\_Veg', ...
    'Apples', 'Oranges', 'Tl\_Fruit', 'Jam', 'Garlic', 'Butter', 'Margarine', ...
    'Olive\_Oil', 'Yoghurt', 'Crisp\_Bread'] ); 

yline(0);
xline(0);
