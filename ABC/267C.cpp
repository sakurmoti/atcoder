#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    //sum[i]はiからM+i-1までの総和。ansは0の場合の答え
    vector<long long> sum(N,0);
    long long ans=0;
    for(int i = 0; i < M; i++){
        sum[0] += A.at(i);
        ans += (i+1)*A.at(i);
        //vector<int> A(N)とすると↑18行目でオーバーフローしWA
    }

    for(int i = 1; i <= N-M; i++){
        sum[i] = sum[i-1] - A.at(i-1) + A.at(i+M-1);
    }

    /*A1~A3をA2~A4にずらす場合ならA1~A3の和を引いてM*A4を足したらよい*/
    long long temp = ans;
    for(int i = 1; i <= N-M; i++){
        temp = temp - sum[i-1] + M*A.at(i+M-1);

        ans = max(ans,temp);
    }

    cout << ans << endl;
    return 0;
}