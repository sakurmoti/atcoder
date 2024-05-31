#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    vector<pair<int, int>> card(N);
    for(int i = 0; i < N; i++){
        cin >> card[i].first >> card[i].second;
    }
    
    // カードを取り除いたかどうかは2^18程度
    // dp[S] := 状態Sのときに手番の人が勝てるかどうか
    vector<bool> dp(1 << N, false);
    
    for(int state = 0; state < (1<<N); state++){
        bitset<20> bit(state);
        for(int i = 0; i < N; i++){
            for(int j = i+1; j < N; j++){
                auto[a,b] = card[i];
                auto[x,y] = card[j];

                if(bit.test(i) && bit.test(j) && (a==x || b==y)){
                    auto prev = bit;
                    prev.reset(i);
                    prev.reset(j);
                    dp[state] = dp[state] or !dp[prev.to_ulong()];
                }
            }
        }
    }

    // for(auto _v : dp) cout << (int)_v << " "; cout << endl;

    if(dp[(1<<N)-1]) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;
    return 0;
}