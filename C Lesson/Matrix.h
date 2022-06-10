/*

En el archivo ".h" se escribe la declaracion, es decir con el ";"

*/

// Esta rutina muestra una matriz de mxn
void MatrixShow(int m, int n, double v[]);

void MatrixT(int n, int m, double v[], double Vec[] );

double DotProd(double x[], double y[], int n);

void MatrixProduct(double m1[], double m2[], double Matrix[], int M, int N, int O);

double maximus(double v[], int s);

void Initialize(double in[], int n);

void Sum(double in[], double out[], int n);

void Ones(double t[], int n);

void Divide(double matrix[], double scalar, double out[], int s);

void MatrixSum(double m1[], double m2[], double mout[], int n);

void PrincipalComponents(double m1[], double m2[], double Matrix[], int M, int N, int O, double sum[]);

void linspace(double x[], double init, double end, int n);

void ConfidenceEllipse(double U[], double l[], double sum[], int ST, int SA);

void PlotPCA(double S[], double U[], double l[], double Dat[], double sum[], int ST, int SA);