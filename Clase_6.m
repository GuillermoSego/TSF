%% Escalamiento de vectores caracterísiticos
samples = [ 
  10.0, 10.7;
  10.4,  9.8;
   9.7, 10.0;
   9.7, 10.1;
  11.7, 11.5;
  11.0, 10.8;
   8.7,  8.8;
   9.5,  9.3;
  10.1,  9.4;
   9.6,  9.6;
  10.5, 10.4;
   9.2,  9.0;
  11.3, 11.6;
  10.1,  9.8;
   8.5,  9.2; ];
%%
% Función dedicada
S = cov( samples );
l = [1.4465, 0.0864];
 
t = ( S - eye(2) * l(1) );
a = -t(1,1) / t(1,2);
U = [1; a] / sqrt( 1 + a^2 );
 
t = ( S - eye(2) * l(2) );
a = -t(2,2) / t(2,1);
U = [ U, [a; 1] / sqrt( 1 + a^2 ) ];

%% 
% El equivalente en nuestro caso es
z = (samples - repmat(mean(samples), size(samples, 1), 1 ) ) * U;
z
%%
% La covarianza de estos datos es igual a
cov(z)
%% Algunas propiedades del principal components
U' * S * U
%%
% Analisis multivariado de resumen de los resultados como
% Calculamos el determinante de S
det(S)
%%
det(S)
det( [l(1), 0; 0, l(2)] )
%%
trace(S)
trace( [l(1),0; 0,l(2)] )
%%
U.* sqrt( repmat(l,2,1) ./ repmat( diag(S),1,2  ) );
U
%% Aqui empieza la clase 6
V = U * sqrt([l(1),0; 0,l(2)]);
V
%%
% Produce L
V' * V
%% 
% Esto es la matriz de covarianza S
V * V'
%%
% Tambien esta esta otra identidad, que funciona para cuando se quiere
% hacer una compresion, ya que hay informacion que se guarda que no se
% necesita
W = U * sqrt( [ 1/l(1),0; 0,1/l(2) ] );
W
%%
% Inversa de L
W' * W 
%%
% Inversa de S
W' * S * W