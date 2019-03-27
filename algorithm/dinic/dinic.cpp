const int MAXN = 20020;
const int MAXM = 200200; 
const int INF = 1e9+7; 
struct Edge
{
    int to; 
    int c;
    int f;
    Edge* next;
    Edge* rev; 
}node[MAXN],edgeNode[(MAXN*2+MAXM*2)*2];
int nodeCnt = 0; 
int s, t; 
int level[MAXN]; 
void InsertEdge(int from,int to,int c){
    Edge *edgex = &edgeNode[nodeCnt++];
    edgex->to = to;     edgex->c = c;     edgex->f = 0;
    edgex->next = node[from].next;      node[from].next = edgex;
    Edge *edgey = &edgeNode[nodeCnt++];
    edgey->to = from;     edgey->c = c;     edgey->f = c;
    edgey->next = node[to].next;     node[to].next = edgey;
    edgex->rev = edgey;      edgey->rev = edgex;
}
void ClearEdge(int x){
    node[x].next = NULL;
}
void ClearMap(int l,int r){
    nodeCnt = 0;
    for (int i = l;i <= r;i++) ClearEdge(i);
}
void RebuildEdge(int x){
    Edge *edge = node[x].next;
    while(edge){
        edge->f = 0;
        edge = edge->next;
    }
}
void RebuildMap(int l,int r){
    for (int i = l;i <= r;i++) RebuildEdge(i);
}
bool bfs() {
    memset(level, -1, sizeof(level));
    queue<int> que; que.push(s); level[s] = 0;
    while (que.size() != 0) {
        int i = que.front(); que.pop();
        for (Edge* it = node[i].next; it != 0; it = it->next)
            if (it->f < it->c && level[it->to] == -1) {
                que.push(it->to);
                level[it->to] = level[i] + 1;
            }
    }
    return level[t] != -1;
}
int dfs(int i = s, int f = INF) {
    if (f == 0) return 0;
    if (i == t) return f;
    int ret = 0;
    for (Edge* it = node[i].next; it != 0 && ret < f; it = it->next)
        if (level[it->to] == level[i] + 1) {
            int val = dfs(it->to, min(it->c - it->f, f - ret));
            it->f += val; it->rev->f -= val;
            ret += val;
        }
    if (!ret) level[i] = -1;
    return ret;
}
 int dinic() {
     int ret = 0;
     while (bfs()) ret += dfs();
     return ret;
 }
int N,M;
int x,y,z;