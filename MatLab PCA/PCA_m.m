M = csvread("1MB_PP_FRR1_FRD11.csv", 1, 0);
M = M(:,2:end);

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

%% Comprobacion de datos
% Tenemos que calcular los eigenvalores y tiene que dar L

eig(cov(Mscale));


%% Graficar
% Ahora vamos a graficar los datos reduciendo la dimensionalidad ya que
% tenemos 4 dimensiones.

% Usualmente se le conoce como grafica de los scores
plot(z1, z2, 'o');

%Observamos si se forman grupo a partir de análisis
%% ¿Qué variables asociamos a cada componente principal?
% Esta grafica típicamente se conoce como gráfica de PCA
plot(A(:,1), A(:,2), 'o');
text(A(:,1), A(:,2), ["L", "W", "L/W", "Area"] ); 

% Vemos la relacion entre los componentes

% Cuando dos puntos estan muy cercas se dice que estos puntos tienen una
% relacion directa, y cuando dos variables estan en dos cuadrantes
% diferentes es porque estos tienen una relacion inversa. Uno crece y el
% otro se hace mas pequeño.

%% 
sqrt(A(:,1).^2 + A(:,2) .^2 );