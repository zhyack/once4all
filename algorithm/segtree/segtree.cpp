const int MAXN = 50010*4;
const int INF = 1e9+7;
//禁用iostream,iomanip,sstream
int lbound[MAXN]; //左端点
int rbound[MAXN]; //右端点
int lchild[MAXN]; //左子结点 -1为空
int rchild[MAXN]; //右子节点 -1为空
int val[MAXN]; //覆盖个数
int sum[MAXN]; //区间和
int add[MAXN]; //区间操作
int nxt,root;//节点数，根节点
int build(int l, int r)
{
    int i = nxt++, mid = (l + r) / 2;
    lbound[i] = l; rbound[i] = r;
    if (r == l) return i;
    lchild[i] = build(l, mid);
    rchild[i] = build(mid + 1, r);
    return i;
}
void buildtree(int l,int r){//建树
    nxt = 0;
    memset(add,0,sizeof(add));
    memset(sum,0,sizeof(sum));
    memset(val,0,sizeof(val));
    root = build(l,r);
}
int query(int pos){//单点查询
    int i = 0, ret = 0;
    while (i != -1) {
        ret += val[i];
        int mid = (lbound[i] + rbound[i]) / 2;
        i = pos <= mid ? lchild[i] : rchild[i];
    }
    return ret;
}
int get(int i){
    if (i == -1) return 0;
    return sum[i] + add[i] * (rbound[i] - lbound[i] + 1);
}
void update(int i){
    sum[i] = get(lchild[i]) + get(rchild[i]);
}
void update(int l, int r, int val, int i = root) {//lazy修改
    if (i == -1) return;
    if (l <= lbound[i] && rbound[i] <= r)
        add[i] += val;
    else if (lbound[i] <= r && rbound[i] >= l) {
        update(l, r, val, lchild[i]);
        update(l, r, val, rchild[i]);
        update(i);
    }
}
void pushdown(int i){//lazy标记下放
    if (lchild[i] != -1) add[lchild[i]] += add[i];
    if (rchild[i] != -1) add[rchild[i]] += add[i];
    sum[i] += add[i] * (rbound[i] - lbound[i] + 1);
    add[i] = 0;
}
int query(int l, int r, int i = root){//区间查询
    if (i == -1) return 0;
    if (l <= lbound[i]  && r >= rbound[i]) return get(i);
    else if (lbound[i] <= r && l <= rbound[i]) {
        pushdown(i);
        return query(l, r, lchild[i])+query(l, r, rchild[i]);
    }
    else return 0;
}
int T,N,x,y,z,Cases = 0;
char s[10];