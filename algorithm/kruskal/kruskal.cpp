const int MAXN = 100010;
const int MAXM = 100010;
const int INF = 1e9+7;
int father[MAXN];
int setCnt;
int kruskal;
struct Edge{
    int x,y,c;
}edge[MAXM];
bool cmp(Edge A,Edge B){
    return A.c < B.c;
}
int Top(int x){
    if (x != father[x]) father[x] = Top(father[x]);
    return father[x];
}
void Union(int x,int y,int c){
    father[x] = y;
    setCnt--;
    kruskal+=c;
}
void Initialize(int n){
    setCnt = n;
    kruskal = 0;
    for (int i = 0;i <= n;i++) father[i] = i;
}
void Kruskal(int n,int m){
    Initialize(n);
    for (int i = 0;i < m;i++){
        int fx = Top(edge[i].x);
        int fy = Top(edge[i].y);
        if (fx != fy) Union(fx,fy,edge[i].c);
    }
}
int N,M,T,K;
int x,y,c;