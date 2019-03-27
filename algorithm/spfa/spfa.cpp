const int MAXN = 1010;
const int MAXM = 1010;
const int INF = 1e9+7;
struct Edge{
    int to,dis;
};
vector<Edge> edge[MAXN];
int spfa[MAXN];
bool exist[MAXN];
queue<int> que;
void ClearMap(int n){
    memset(exist,false,sizeof(exist));
    for (int i = 0;i <= n;i++) edge[i].clear();
    while(!que.empty()) que.pop();
}
void InsertEdge(int x,int y,int c){
    Edge tmp;
    tmp.dis = c;
    tmp.to = y;    edge[x].push_back(tmp);
//    tmp.to = x;    edge[y].push_back(tmp);
}
void SPFA(int n,int s){
    que.push(s);
    fill(spfa,spfa+n+1,INF);
    spfa[s] = 0;
    exist[s] = true;
    while(!que.empty()){
        int x = que.front();
        que.pop();
        vector<Edge>::iterator it;
        for (it = edge[x].begin();it != edge[x].end();it++){
            int y = it->to;
            int z = it->dis;
            if (spfa[x]+z < spfa[y]){
                spfa[y] = spfa[x]+z;
                if (!exist[y]) {
                    que.push(y);
                    exist[y] = true;
                }
            }
        }
        exist[x] = false;
    }
}
int N,M,K,s;
int x,y,z;