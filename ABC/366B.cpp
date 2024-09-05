#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    vector<vector<char>> S(110, vector<char>(110,'*'));
    int len = -1;
    for(int i = 0; i < N; i++){
        string T; cin >> T;
        chmax(len, (int)T.size());
        for(int j = 0; j < T.size(); j++){
            S[i][j] = T[j];
        }
    }

    vector<vector<char>> ans(110, vector<char>(110, '*'));
    for(int j = 0; j < len; j++){
        for(int i = N-1; i >= 0; i--){
            ans[j][N-i-1] = S[i][j];
        }
    }

    for(int i = 0; i < len; i++){
        int last = -1;
        for(int j = 0; j < N; j++){
            if(ans[i][j] == '*'){
                if(last < 0) last = j;
                continue;
            }

            if(last >= 0) cout << string(j-last, '*');

            cout << ans[i][j];
            last = -1;
        }
        cout << endl;
    }
    return 0;
}