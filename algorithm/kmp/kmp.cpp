void findNext(char *strB,int next[]){
    int M = strlen(strB);
    int j = -1;
    next[0] = -1;
    for (int i = 1;i < M;i++){
        while(j>=0 && strB[j+1]!=strB[i]) j = next[j];
        if (strB[j+1] == strB[i]) j++;
        next[i] = j;
    }
}
void kmp(char *strB,char *strA,int next[]){
    findNext(strB,next);
    int N = strlen(strA);
    int M = strlen(strB);
    int cnt = 0;
    int j = -1;
    for (int i = 0;i < N;i++){
        while(j>=0 && strB[j+1]!=strA[i]) j = next[j];
        if (strB[j+1] == strA[i]) j++;
        if (j == M-1) {
            j = next[j];
            cnt++;
        }
    }
    cout << cnt << endl;
}