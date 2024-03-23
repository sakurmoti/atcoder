#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,X; cin >> N >> X;

    vector<ll> A(N+1), B(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i] >> B[i];
    }

    vector<ll> csum(N+1, 0); // ステージiまで1回ずつクリアするのにかかる時間
    vector<ll> minB(N+1, 1e18); // ステージiまでの中でゲーム時間が最も短いもの
    for(int i = 1; i <= N; i++){
        csum[i] = csum[i-1] + A[i] + B[i];
        minB[i] = min(minB[i-1], B[i]);
    }

    ll ans = 9e18;
    // ステージiまでクリアする場合
    for(int i = 1; i <= N; i++){
        if(X-i < 0) break;
        ll time = csum[i] + minB[i] * (X-i);
        ans = min(ans, time);
    } 

    cout << ans << endl;
    return 0;
}