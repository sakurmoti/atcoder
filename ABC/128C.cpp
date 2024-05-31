#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,M; cin >> N >> M;
    vector<bitset<10>> sw(N, bitset<10>(0));

    for(int i = 0; i < M; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int s; cin >> s;
            s--;
            sw[s].set(i);
        }
    }

    // for(auto v : sw) cout << v << endl; cout << endl;

    bitset<10> p(0);
    for(int i = 0; i < M; i++){
        int q; cin >> q;
        p.set(i,q);
    }

    int ans = 0;
    for(int i = 0; i < (1 << N); i++){
        bitset<10> state(i);
        bitset<10> now(0);
        for(int j = 0; j < 10; j++){
            if(state.test(j)){
                now ^= sw[j];
            }
        }

        bool flag = true;
        for(int j = 0; j < M; j++){
            if(p[j] != now[j]){
                flag = false;
            }
        }

        if(flag) ans++;
    }

    cout << ans << endl;
    return 0;
}