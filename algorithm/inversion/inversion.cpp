const int MAXN = 100010;
const int MAXM = 100010;
const int INF = 1e9+7;
int A[MAXN],B[MAXN];
int N,K;
long long res;
void Inversion(int l,int r){
    if (l == r) return;
    long long mid = (l+r)/2;
    Inversion(l,mid);
    Inversion(mid+1,r);
    long long i = l,j = mid+1,k = l;
    while(i <= mid && j <= r){
        if (A[i] <= A[j]) B[k++] = A[i++];
        else{
            res += mid-i+1;
            B[k++] = A[j++];
        }
    }
    while(i <= mid) B[k++] = A[i++];
    while(j <= r) B[k++] = A[j++];
    for (i = l;i <= r;i++) A[i] = B[i];
}