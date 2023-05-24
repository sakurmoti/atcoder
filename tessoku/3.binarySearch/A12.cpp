#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    long long ok = 1e9;
    long long ng = 0;
    while(ok - ng > 1){
        //mid秒時点で枚数が超えているか確認する
        long long mid = (ok+ng)/2;
        long long paper = 0;
        for(int i = 0; i < N; i++){
            paper += mid/A.at(i);
        }

        if(paper < K){
            ng = mid;
        
        }else{
            ok = mid;

        }
    }

    cout << ok << endl;
    return 0;
}