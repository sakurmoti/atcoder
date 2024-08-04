#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll N,K; cin >> N >> K;
    
    // cnt[i] := iになるまでに押した回数
    vector<ll> cnt(1e5, -1);

    auto A = [&](int x){
        string s = to_string(x);
        int y = 0;
        for(int i = 0; i < s.size(); i++){
            y += (s[i] - '0');
        }

        return (x+y)%100000;
    };

    int now = N;
    bool flag = false;
    ll k = 0;
    while(k < K){
        // cout << k << " " << now << endl;
        if(flag || cnt[now] < 0){
            cnt[now] = k;
            k++;
            now = A(now);

        }else{
            flag = true;
            ll len = k-cnt[now];
            K -= k;
            K %= len;
            k = 0;
        }
    }

    cout << now << endl;
    return 0;
}