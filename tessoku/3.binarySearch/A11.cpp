#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,X;
    cin >> N >> X;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int ng=-1;
    int ok=N;
    int mid = (ok+ng)/2;
    while(abs(ok-ng) >= 2){
        if(A.at(mid) < X){
            ng = mid;

        }else{
            ok = mid;
        
        }

        mid = (ok+ng)/2;
        //printf("ok=%d, ng=%d, mid=%d\n",ok,ng,mid);
    }

    cout << ok+1 << endl;
    return 0;
}