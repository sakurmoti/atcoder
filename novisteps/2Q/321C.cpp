#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

vector<ll> like321;
void make_num(ll x){
    like321.push_back(x);
    for(int i = 0; i < x%10; i++){
        make_num(x*10 + i);
    }
}

int main(){
    for(int i = 1; i < 10; i++){
        make_num(i);
    }

    sort(ALL(like321));
    // for(auto &_v : like321) cout << _v << " "; cout << endl;

    int K; cin >> K;
    cout << like321[K-1] << endl;
    return 0;
}