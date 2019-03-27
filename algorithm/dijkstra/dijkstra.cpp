const int MAXN = 1010;
const int MAXM = 1010;
const int INF = 1e9+7;
struct Edge{
    int to,dis;
};
bool operator <(const Edge &A,const Edge &B){
    return A.dis > B.dis;
}
vector<Edge> edge[MAXN];
int dijkstra[MAXN];
bool inset[MAXN];
priority_queue<Edge> que;
void ClearMap(int n){
    for (int i = 0;i <= n;i++) edge[i].clear();
    while(!que.empty()) que.pop();
    fill(dijkstra,dijkstra+n+1,INF);
    memset(inset,false,sizeof(inset));
}
void InsertEdge(int x,int y,int c){
    Edge tmp;
    tmp.dis = c;
    tmp.to = y;    edge[x].push_back(tmp);
//    tmp.to = x;    edge[y].push_back(tmp);
}
void Dijkstra(int n,int s){
    dijkstra[s] = 0;
    for (vector<Edge>::iterator it = edge[s].begin();it != edge[s].end();it++) que.push(*it);
    inset[s] = true;
    while(!que.empty()){
        Edge e = que.top();
        que.pop();
        int x = e.to;
        if (inset[x]) continue;
        inset[x] = true;
        dijkstra[x] = e.dis;
        for (vector<Edge>::iterator it = edge[x].begin();it != edge[x].end();it++){
            Edge e0 = *it;
            e0.dis += e.dis;
            if (!inset[e0.to]) que.push(e0);
        }
    }
}
int N,M,K,s;
int x,y,z;