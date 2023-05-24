#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> A(N+1);
    for(int i = 1; i <= N; i++) cin >> A[i];

    //尺取り法をしてみる
    int idx = 1;
    long long ans = 0;
    for(int i = 1; i < N; i++){
        while(idx < N && (A.at(idx+1)-A.at(i)) <= K ){
            idx++;
        }

        //cout << idx << endl;
        ans += idx - i;
    }

    cout << ans << endl;
    return 0;
}