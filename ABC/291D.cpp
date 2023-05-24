#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;

int countCard(pair<int, int> c1, pair<int, int> c2){
    int ret = 0;
    if(c1.first != c2.first) ret++;
    if(c1.first != c2.second) ret++;
    if(c1.second != c2.first) ret++;
    if(c1.second != c2.second) ret++;

    return ret;
}

int main(){
    int N;
    cin >> N;

    vector<pair<int, int>> card(N);
    for(auto &x : card) cin >> x.first >> x.second;
    
    mint ans = 1;
    for(int i = 0; i < N-1; i++){
        int cnt = countCard(card[i], card[i+1]);
        
    }

    return 0;
}