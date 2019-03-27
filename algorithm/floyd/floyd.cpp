const int MAXN = 550;
const int MAXM = 25500;
const unsigned long long INF = (-1ULL)>>3;
long long floyd[MAXN][MAXN];
void ClearMap(int n){
    for (int i = 0;i <= n;i++)
        for (int j = 0;j <= n;j++)
            floyd[i][j] = INF;
    for (int i = 0;i <= n;i++) floyd[i][i] = 0;
}
void Floyd(int n){
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                floyd[i][j] = min(floyd[i][k]+floyd[k][j],floyd[i][j]);
}
int N,M,T,Cases = 0;
int x,y;