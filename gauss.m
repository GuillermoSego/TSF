%Metodo de Gauss

n = input('Introduce la dimension de la matriz: ');
%A = [2 -1 1; -3 1 1; 5 1 -2];
%B = [3; 2; 1];
A = zeros(n);
X = zeros(1,n);
B = zeros(n,1);

%Escaneo de matriz A
for i =1: n
    for j = 1:n
        fprintf('Introduce el valor de (%i, %i): ', i, j);
        A(i, j) = input('');
    end
end

%Escaneo de la matriz B
for i=1:n
    fprintf('Introduce el valor de (%i, 1): ',i)
    B(i) = input('');
end


MAT = [A B];


%Diagonalizacion de la matriz
for j=1:n-1
    for i=j+1:n
        MAT(i,:) = MAT(i,:) + MAT(j,:)*(-MAT(i,j)/MAT(j,j));
    end
end



%Sustitucion hacia atras
for i=n:-1:1
    suma = 0;
    %X(i) = MAT(i, 3+1);
    if i<n
        %for j = i+1:3
        %   X(i) = X(i) - X(j)*MAT(i,j);
        %end
        for j = n  :-1:1  
            suma = MAT(i,j)*X(j)+suma;
        end
    end
 
    
    %X(i) = X(i)/MAT(i,i);
    X(i) = (-suma + MAT(i, n+1))/MAT(i,i)
end
