const int MAXN = 4000040;
const int INF = 1e9+7;
long long phi[MAXN];
void Euler(int N){
    for(int i = 1; i <= N; i ++) phi[i] = i;
    for(int i = 2; i <= N; i ++)
        if(phi[i] == i)    for(int j = i; j <= N; j += i)
                phi[j] = phi[j] / i * (i - 1);
}