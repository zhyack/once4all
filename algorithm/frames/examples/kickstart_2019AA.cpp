//#pragma comment(linker, "/STACK:1024000000,1024000000") //when you need more memory for function recursion, uncomment this
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
const int MAXM = 1e5+10;
const int INF = 1e9+7;
const long long llINF = 1e18+7;
const int dir4[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
const int dir8[8][2]={{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};
const double eps = 1e-10;

long long a[MAXN];

long long N,M,T = INF,Cases = 0;

int main(){
    // ios_base::sync_with_stdio(0); // uncomment this if you need really fast input&output with cin&cout
    //****************COMMENT THIS*******************//
    // freopen("input.txt", "r", stdin); //work with stdin from input.txt
    // freopen("output.txt", "w", stdout); //work with stdout from output.txt
    //****************WHEN SUBMMIT*******************//

    // scanf("%d",&T);
    cin >> T;
    // while(T-- && ~(scanf("%d%d",&N,&M)) && Cases++){
    while(T-- && (cin >> N >> M) && ++Cases){

        // define your input procedure
        for (int i = 0;i < N;i++) cin >> a[i];
        
        // define your solution
        sort(a,a+N);
    	long long pre_sum = 0;
    	long long ans = llINF;
    	for (int i = 0;i < M;i++) pre_sum += a[i];
    	for (int i = M-1;i < N; i++){
    		if (M*a[i]-pre_sum<ans) ans = M*a[i]-pre_sum;
    		pre_sum += a[i+1]-a[i-M+1];
    	}
        
        // printf("Case #%d: ", Cases);
        cout << "Case #" << Cases << ": ";
        
        //define your output procedure
        // printf("%d\n", Ans);
        cout << ans << endl;

    }
    return 0;
}
