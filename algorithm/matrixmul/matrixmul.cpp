int N,mod;
struct Matrix{
    static const int matn = 16;
    int m[matn][matn];
}mat,tmp;
Matrix operator *(Matrix A,Matrix B){
    Matrix C;
    memset(C.m,0,sizeof(C.m));
    for (int i = 0;i < Matrix::matn;i++)
        for (int j = 0;j < Matrix::matn;j++)
            for (int k = 0;k < Matrix::matn;k++)
                C.m[i][j] = (C.m[i][j]+A.m[i][k]*B.m[k][j])%mod;
    return C;
}
Matrix MatrixMul(Matrix mat,int n){
    if (n == 1) return mat;
    tmp = MatrixMul(mat,n/2);
    if (n%2) return tmp*tmp*mat;
    else return tmp*tmp;
}