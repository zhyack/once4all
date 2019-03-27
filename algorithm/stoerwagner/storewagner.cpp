const int MAXN = 220;
const int MAXM = 40400;
const int INT_MAX = 1e9+7;
bool visited[MAXN];
int dis[MAXN];
bool combined[MAXN];
int graph[MAXN][MAXN];
int s, t, minCut,x,y,z;
int N,M,T,Cases = 0;
void Prim(){
     int i, j, Max, tmp;
     memset(visited, false, sizeof(visited));
     memset(dis, 0, sizeof(dis));
     s = t = -1;
     for (i = 1; i <= N; i++){
         Max = -INT_MAX;
         for (j = 1; j <= N; j++){
             if (!combined[j] && !visited[j] && dis[j] > Max){
                tmp = j;
                Max = dis[j];
             }
         }
         if (t == tmp) return;
         s = t; t = tmp;
         minCut = Max;
         visited[tmp] = true;
         for (j = 1; j <= N; j++){
             if (!combined[j] && !visited[j]){
                dis[j] += graph[tmp][j];
             }
         }
     }
}
int StoerWagner(){
    int i, j;
    memset(combined, false, sizeof(combined));
    int ans = INT_MAX;
    for (i = 1; i < N; i++){
        Prim();
        if (minCut < ans) ans = minCut;
        if (ans == 0) return 0;
        combined[t] = true;
        for (j = 1; j <= N; j++){
            if (!combined[j]){
               graph[s][j] += graph[t][j];
               graph[j][s] += graph[j][t];
            }
        }
    }
    return ans;
}