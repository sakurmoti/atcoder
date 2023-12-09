#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N,M; cin >> N >> M;
    vector<ll> A(N);
    for(auto &_v : A) cin >> _v;

    // 整数iが手札にあるときにi+1を出さない方が良い
    // すると全探索すべきは最初の一枚目のみ
    ll sum = 0;
    map<ll, ll> card;
    for(ll i = 0; i < N; i++){
        sum += A[i];
        card[A[i]]++;
    }

    vector<pair<ll, ll>> B;
    for(auto v : card) B.push_back(v);
    
    // 一周できる場合は無限ループを防ぐため例外処理
    ll K = B.size();
    if(K == M){
        cout << 0 << endl;
        return 0;
    }

    // lは区切れの先頭
    ll l = 0;
    for(ll i = 0; i < K; i++){
        if(B[(i+1)%K].first != (B[i].first+1)%M ){
            l = i;
            break;
        }
    }

    vector<ll> ans(K, -1);
    for(ll i = 0; i < K; i++){
        ll idx = (l-i+K)%K;
        ans[idx] = sum;

        if(B[(idx+1)%K].first == (B[idx].first + 1)%M ){
            // 続いているので
            ans[idx] = ans[(idx+1)%K];
        }

        // 手札idxを全て出す
        ans[idx] -= B[idx].first * B[idx].second;
    }

    cout << *min_element(ALL(ans)) << endl;
    return 0;
}