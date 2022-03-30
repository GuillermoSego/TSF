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

n = size(samples, 1);
meanScale = samples - repmat( mean(samples), n, 1 );

% Metodo 1:
[A, L, U] = svd( meanScale' * meanScale / (n-1) )

% Método 2:
[A, B, U] = svd( meanScale );

U
L = (B .* B) ./ (n-1)
A * B

V = [ U(:,1) * sqrt( L(1,1) ), U(:,2) * sqrt( L(2,2) ) ]
S = V*V'
