const int MAXN = 510;
const int MAXM = 50050;
const int INF = 1e9+7;
int graph[MAXN][MAXN];
int dis[MAXN];
bool inset[MAXN];
int prim;
bool Prim(int n){
    prim = 0;
    for (int i = 1;i <= n;i++) dis[i] = graph[1][i];
    memset(inset,false,sizeof(inset));
    inset[1] = true;
    for (int i = 1;i < n;i++){
        int p = 0,d = INF;
        for (int j = 1;j <= n;j++){
            if (!inset[j] && dis[j] < d){
                d = dis[j];
                p = j;
            }
        }
        prim += d;
        inset[p] = true;
        for (int j = 1;j <= n;j++)
            if (graph[p][j] < dis[j]) dis[j] = graph[p][j];
    }
    return !inset[0];
}