const int MAXN = 1010;
const int MAXM = 1010;
const int INF = 1e9+7;
priority_queue<int, vector<int>, greater<int> > que;
int topo[MAXN];
int topoCnt;
bool exist[MAXN];
vector<int> edges[MAXN];
int d[MAXN];
void InsertEdge(int x,int y){
    edges[x].push_back(y);
    d[y]++;
}
void ClearMap(int n){
    topoCnt = 0;
    memset(exist,0,sizeof(exist));
    memset(d,0,sizeof(d));
    while(!que.empty()) que.pop();
    for (int i = 0;i <= n;i++) edges[i].clear();
}
bool Topo(int n){
    que.push(0);
    while(!que.empty()){
        int now = que.top();
        que.pop();
        topo[topoCnt++] = now;
        for(vector<int>::iterator it = edges[now].begin();it != edges[now].end();it++){
            int next = *it;
            if (--d[next] == 0){
                que.push(next);
                exist[next] = true;
            }
        }
    }
    if (topoCnt < n+1) return false;
    else return true;
}
int N,M;
int x,y;