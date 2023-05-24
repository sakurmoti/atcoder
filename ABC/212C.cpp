#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T &a, T b){
    if(a > b) a = b;
}

int main(){
    int N,M;
    cin >> N >> M;
    
    vector<int> A(N),B(M);
    for(int i = 0; i < N; i++) cin >> A.at(i);
    for(int i = 0; i < M; i++) cin >> B.at(i);

    sort(B.begin(), B.end());

    //Aのすべての要素に対してBに二分探索をすればO(NlogM)で計算可能
    int ans=1e9;
    for(int i = 0; i < N; i++){
        int ok = M;
        int ng = -1;
        int mid;
        
        while((ok-ng) > 1){
            mid = (ok+ng)/2;
            
            if(A.at(i) < B.at(mid)){
                ok = mid;
            
            }else{
                ng = mid;

            }

            //printf("ok=%d, ng=%d\n",ok,ng);

        }

        //B.at(mid)はA.at(i)よりも大きい。
        chmin(ans, abs(A.at(i)-B.at(mid)));
        if(mid != 0) chmin(ans, abs(A.at(i)-B.at(mid-1)));
        if(mid != M-1) chmin(ans, abs(A.at(i)-B.at(mid+1)));
        //cout << ans << endl;
    }

    cout << ans << endl;
    return 0;
}