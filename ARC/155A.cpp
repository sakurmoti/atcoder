#include <bits/stdc++.h>
using namespace std;

string solve(){
    long long N,K;
    cin >> N >> K;

    string S;
    cin >> S;

    if(2*N <= K){
        //Sの中に回文があればok？
        long long modulo = K%(2*N);
        if(N <= modulo*2) return "No";

        for(int i = 1; i <= modulo; i++){
            if(S.at(modulo-i) != S.at(modulo+i-1)){
                return "No";
            }
        }
        
        return "Yes";
    }

    //そうでなければN+Kの長さの回文が作れるかどうか
    if((N+K) % 2 == 0){
        //偶数の場合
        long long mid1 = (N+K)/2;
        long long mid2 = mid1 - 1;
        
        int cnt = 0;
        while(mid1+cnt < N){
            if(S.at(mid1+cnt) != S.at(mid2-cnt)){
                return "No";
            }
            cnt++;
        }
        cnt--;

        string T = S.substr(0, K);
        reverse(T.begin(), T.end());

        //頭につけても大丈夫か
        for(int i = 0; i < K; i++){
            if(T.at(i) != S.at(S.size()-1-i)){
                return "No";
            }
        }

    }else{
        //奇数の場合
        long long mid = (N+K)/2;
        
        int cnt = 0;
        while(mid+cnt < N){
            if(S.at(mid+cnt) != S.at(mid-cnt)){
                return "No";
            }
            cnt++;
        }
        cnt--;

        string T = S.substr(0, K);
        reverse(T.begin(), T.end());

        for(int i = 0; i < K; i++){
            if(T.at(i) != S.at(S.size()-1-i)){
                return "No";
            }
        }
    }

    return "Yes";
}

int main(){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        cout << solve() << endl;
    }

    return 0;
}