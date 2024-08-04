#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int H,W; cin >> H >> W;
    vector<vector<int>> P(H, vector<int>(W));
    for(auto &_v : P) for(auto &_vv : _v) cin >> _vv;

    int ans = -1;
    for(int i = 1; i < (1<<H); i++){
        bitset<10> bits(i);
        int h = bits.count();
        int w = -1;

        map<int, int> dict;
        for(int j = 0; j < W; j++){
            int f = 0;
            bool ok = true;
            for(int k = 0; k < H; k++){
                if(bits.test(k)){
                    if(f <= 0) f = P[k][j];
                    else if(f != P[k][j]) ok = false;
                }
            }

            if(ok){
                dict[f]++;
                chmax(w, dict[f]);
            }
        }

        chmax(ans, h*w);
    }

    cout << ans << endl;
    return 0;
}