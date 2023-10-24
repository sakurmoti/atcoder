#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<pair<ll, ll>> E(N);
    for(int i = 0; i < N; i++){
        cin >> E[i].first >> E[i].second;
        E[i].second += E[i].first;
    }

    sort(E.begin(), E.end());

    priority_queue<ll, vector<ll>, greater<ll>> pque;
    ll ans = 0;
    ll t = 0;
    int i = 0;
    while(true){
        // 空のとき、次のイベントまで時刻をとばす
        if(pque.empty()){
            if(i >= N) break;
            t = E[i].first;
        }

        // 時刻tでイベントが始まる場合
        while(i < N && E[i].first == t){
            pque.push(E[i].second);
            i++;
        }

        // もう終わったイベントは廃棄
        while(!pque.empty() && pque.top() < t) pque.pop();

        // そうでなければ、終わるのが速い順に処理
        if(!pque.empty()){
            pque.pop();
            ans++;
        }
        t++;
    }
    cout << ans << endl;
    return 0;
}