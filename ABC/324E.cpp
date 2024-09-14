#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x, y;};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    string T; cin >> T;

    vector<string> S(N);
    for(auto &_v : S) cin >> _v;

    // 前から、後ろから見たときidxのどこまで部分列になるか
    vector<int> prev(N),suf(N);
    for(int i = 0; i < N; i++){
        int k = 0;
        for(int j = 0; j < S[i].size(); j++){
            if(k < T.size() && S[i][j] == T[k]){
                k++;
            }
        }
        prev[i] = k;
        
        k = 0;
        for(int j = S[i].size()-1; j >= 0; j--){
            if(k < T.size() && S[i][j] == T[T.size()-1-k]){
                k++;
            }
        }
        suf[i] = k;
    }

    // for(auto &_v : prev) cout << _v << " "; cout << endl;
    // for(auto &_v : suf) cout << _v << " "; cout << endl;

    // prev, sufの組合せから和がT.size()以上になればok
    sort(ALL(suf));
    ll ans = 0;
    for(int i = 0; i < N; i++){
        int v = (int)(T.size()) - prev[i];
        int idx = lower_bound(ALL(suf), v) - suf.begin();
        
        // cout << idx << endl;
        ans += (int)suf.size() - idx;
    }

    cout << ans << endl;
    return 0;
}