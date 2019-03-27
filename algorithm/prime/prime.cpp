const int MAXN = 100010;
const int MAXM = 10010;
int primeChart[MAXM];
bool isPrime[MAXN];
int primeCnt;
int N,M,T;
int split[MAXM][2];
int splitCnt;
void MakePrimeChart(int cell){
    primeCnt = 0;
    memset(isPrime,true,sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2;i < cell;i++){
        if (!isPrime[i]) continue;
        primeChart[primeCnt++] = i;
        for (int j = 2;j <= cell/i;j++) isPrime[i*j] = false;
    }
}
void Split(int x){
    int p = 0;
    memset(split,0,sizeof(split));
    splitCnt = 0;
    while(x > 1 && p < primeCnt){
        if (x%primeChart[p] == 0) split[++splitCnt][0] = primeChart[p];
        while(x%primeChart[p] == 0) split[splitCnt][1]++,x/=primeChart[p];
        p++;
    }
    if (x > 1) split[++splitCnt][0] = x,split[splitCnt][1]++;
    for (int i = splitCnt;i > 1;i--) cout << split[i][0] << " " << split[i][1] << " ";
    cout << split[1][0] << " " << split[1][1] << "\n";
}