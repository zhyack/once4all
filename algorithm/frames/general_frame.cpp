//#pragma comment(linker, "/STACK:1024000000,1024000000") //when you need more memory for function recursion, uncomment this
#include <bits/stdc++.h>
using namespace std;

//*****************************************Input************************************************
inline int read(int &x){scanf("%d",&x);return x;}
inline long long read(long long &x){scanf("%I64d",&x);return x;}
inline char read(char c){c = getchar();return c;}
inline char* read(char* &x){scanf("%s",x);return x;}
inline char* readln(char* &x){gets(x);return x;}
inline string read(string &x){cin >> x;return x;}
inline string readln(string &x){getline(cin,x);return x;}
inline float read(float &x){scanf("%f",&x);return x;}
inline double read(double &x){scanf("%lf",&x);return x;}
inline void ToString(char* x,string &y){y = x;}
inline void ToChar(string x,const char*y){y = x.c_str();}
template <typename T> inline void read(vector<T> &a,int n){
    a.clear();      T x;
    for (int i = 0;i < n;i++)    a.push_back(read(x));
}
template <typename T> inline void read(T a[],int n){
    for (int i = 0;i < n;i++)    read(a[i]);
}
//*****************************************Output************************************************
inline int write(int x){printf("%d",x);return x;}
inline int writeln(int x){printf("%d\n",x);return x;}
inline long long write(long long x){printf("%I64d",x);return x;}
inline long long writeln(long long x){printf("%I64d\n",x);return x;}
inline char write(char c){putchar(c);return c;}
inline char writeln(char c){putchar(c);putchar('\n');return c;}
inline char* write(char* x){printf("%s",x);return x;}
inline char* writeln(char* x){puts(x);return x;}
inline string write(string x){cout << x;return x;}
inline string writeln(string x){cout << x << '\n';return x;}
inline float write(float x){printf("%f",x);return x;}
inline float writeln(float x){printf("%f\n",x);return x;}
inline double write(double x){printf("%lf",x);return x;}
inline double writeln(double x){printf("%lf\n",x);return x;}
template <typename T> inline void write(vector<T> &a,int n){
    for (int i = 0;i < n-1;i++)  {      write(a[i]);        putchar(' ');       }
    writeln(a[n-1]);
}
template <typename T> inline void writeln(vector<T> &a,int n){
    for (int i = 0;i < n;i++)   writeln(a[i]);
}
template <typename T> inline void write(T a[],int n){
    for (int i = 0;i < n-1;i++)  {      write(a[i]);        putchar(' ');       }
    writeln(a[n-1]);
}
template <typename T> inline void writeln(T a[],int n){
    for (int i = 0;i < n;i++)   writeln(a[i]);
}
//******************************************Compare*************************************************
template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}
template <class T> inline T max1(T a, T b) { return a > b ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }
inline int jud(double a, double b, eps){
    if(abs(a) < eps && abs(b) < eps) return 0;
    else if(abs1(a - b) / abs1(a) < eps) return 0;
    if(a < b) return -1;
    return 1;
}
template <typename t> inline int jud(t a, t b){
    if(a < b) return -1;
    if(a == b) return 0;
    return 1;
}


//******************************************Code Here*************************************************

const int MAXN = 1e5+10;
const int MAXM = 1e5+10;
const int INF = 1e9+7;
const long long llINF = 1e18+7;
const int dir4[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};
const int dir8[8][2]={{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};
const double eps = 1e-10;



long long N,M,T = INF,Cases = 0;

int main(){
    ios_base::sync_with_stdio(0); // uncomment this if you need really fast input&output with cin&cout
    //****************COMMENT THIS*******************//
    freopen("input.txt", "r", stdin); //work with stdin from input.txt
    freopen("output.txt", "w", stdout); //work with stdout from output.txt
    //****************WHEN SUBMMIT*******************//

    scanf("%d",&T);
    // cin >> T;
    while(T-- && ~(scanf("%d%d",&N,&M)) && Cases++){
    // while(T-- && (cin >> N >> M) && ++Cases){

        // define your input procedure

        // define your solution
        
        // printf("Case #%d: ", Cases);
        cout << "Case #" << Cases << ": ";
        
        //define your output procedure
        // printf("%d\n", Ans);
        cout << Ans << endl;

    }
    return 0;
}
