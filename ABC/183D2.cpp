#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//イベントソートによる解答 eventのソートがボトルネックでO(NlogN)
//時刻が大きいときにimos法は使えないのでこちらの方が高速
int main(){
    int N,W;
    cin >> N >> W;

    vector<pair<ll, int>> event;
    for(int i = 0; i < N; i++){
        int S,T,P;
        cin >> S >> T >> P;

        event.push_back(make_pair(S, P));
        event.push_back(make_pair(T, -P));
    }

    sort(event.begin(), event.end());

    ll water = 0;
    bool overflow = false;
    for(int i = 0; i < event.size()-1; i++){
        water += event[i].second;
        if(water > W){
            overflow = true;
        }
    }

    if(overflow) cout << "No" << endl;
    else cout << "Yes" << endl;


    return 0;
}