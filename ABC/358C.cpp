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
    vector<bitset<10>> popcorn(N, 0);
    for(int i = 0; i < N; i++){
        string S; cin >> S;
        bitset<10> p(0);
        for(int j = 0; j < M; j++){
            if(S[j] == 'o'){
                p.set(j);
            }
        }

        popcorn[i] = p;
    }

    int ans = 20;
    for(int i = 0; i < (1<<N); i++){
        bitset<10> bits(i);
        bitset<10> got_pop(0);
        for(int j = 0; j < 10; j++){
            if(bits.test(j)){
                got_pop |= popcorn[j];
            }
        }
        // cout << got_pop << endl;

        bool ok = true;
        for(int j = 0; j < M; j++){
            if(!got_pop.test(j)){
                ok = false;
            }
        }

        if(ok) chmin(ans, (int)bits.count());
    }

    cout << ans << endl;
    return 0;
}