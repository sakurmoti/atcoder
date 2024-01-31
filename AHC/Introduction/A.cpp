#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int D; cin >> D;
    vector<int> c(26);
    for(auto &_v : c) cin >> _v;

    vector<vector<int>> s(D, vector<int>(26));
    for(auto &_v : s) for(auto &_vv : _v) cin >> _vv;

    
    return 0;
}