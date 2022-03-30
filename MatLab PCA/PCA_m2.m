%% Retirar componentes de PCA
% Tenemos que quitar los datos de los componentes principales que no
% afectan en el análisis.

%% Guardar los datos en una celda
% 

arch = dir("*.csv");

ST = size(arch, 1);

datos = cell(size(arch));
dim = zeros(ST,1);

for i=1:size(arch, 1)

    datos{i} = csvread(arch(i).name, 1, 0);
    datos{i} = datos{i}(:,2:3);   

    dim(i) = size(datos{i}, 1);    

end

%% Creacion de matriz de datos
M = zeros(min(dim), ST*2);

for i=1 : ST
    M(:,(i*2-1):(i*2) ) = datos{i}(1:min(dim),:);
end

%% Checar si tenemos NaN en la matriz
% Cambiamos el valor de NaN con 1 y encontramos las columnas y los
% renglones en los que estan. 

col = find( sum( isnan(M) ) ~= 0 );
row = find( sum( isnan(M), 2 ) ~= 0 );

%% Reemplazar los NaN con los promedios
% Calculamos primero las medias omitiendo los valores 
MeanTmp = mean(M,'omitnan');

for i=1:(ST*2)
    for j=1:(length(M))
        if isnan(M(j,i)) ~= 0
            M(j, i) = MeanTmp(i);
        end
    end
end

%% Creacion de matriz escalada
% Creamos una nueva celda para la matriz escalada

Mscale = zeros(min(dim), ST*2);

Mscale = (M  - mean(M) ) ./ (std( M ));
%% Método 2
% No podemos aplicar el metodo 2 ya que el programa se queda sin memoria
%% Método 1
% Hay que calcular la matriz de cov
% A - Transpuesta
% L - Eigenvectores
% U - Matriz de cosenos directores

n = size(Mscale, 1);
[A, L, U] = svd( Mscale' * Mscale / (n-1) );

%% Calculamos las z
z1 = ( Mscale ) * A(:,1) ;
z2 = ( Mscale ) * A(:,2) ;
z3 = ( Mscale ) * A(:,3) ;
z4 = ( Mscale ) * A(:,4) ;
z5 = ( Mscale ) * A(:,5) ;
z6 = ( Mscale ) * A(:,6) ;
z7 = ( Mscale ) * A(:,7) ;
z8 = ( Mscale ) * A(:,8) ;

%% Comprobacion de datos
% Tenemos que calcular los eigenvalores y tiene que dar L

eig(cov(Mscale));


%% Graficar
% Ahora vamos a graficar los datos reduciendo la dimensionalidad ya que
% tenemos 4 dimensiones.

% Usualmente se le conoce como grafica de los scores
plot(z1, z2, 'o');

%Observamos si se forman grupo a partir de análisis

%% Puntos que salen de la media
% Ahora calculamos los puntos que se salen de la media ordenandolos

distm = [(1:length(z1))', z1.^2 + z2.^2];
disto = sortrows(distm, -2);

indexo = find( disto(:,2)>= 100 );

index = disto(indexo, 1);

M(index,:)

%% ¿Qué variables asociamos a cada componente principal?
% Esta grafica típicamente se conoce como gráfica de PCA
figure;
plot(A(:,1), A(:,2), 'o');
text(A(:,1), A(:,2), ["L1", "W1", "L2", "W2","L3", "W3", "L4", "W4"]); 

% Vemos la relacion entre los componentes

% Cuando dos puntos estan muy cercas se dice que estos puntos tienen una
% relacion directa, y cuando dos variables estan en dos cuadrantes
% diferentes es porque estos tienen una relacion inversa. Uno crece y el
% otro se hace mas pequeño.



