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
    constexpr int M = 1000;
    vector<vector<int>> paper(M+10, vector<int>(M+10, 0));
    for(int i = 0; i < N; i++){
        int lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;

        paper[ly][lx]++;
        paper[ry][lx]--;
        paper[ly][rx]--;
        paper[ry][rx]++;
    }

    for(int i = 0; i <= M; i++){
        for(int j = 1; j <= M; j++){
            paper[i][j] += paper[i][j-1];
        }
    }

    for(int i = 1; i <= M; i++){
        for(int j = 0; j <= M; j++){
            paper[i][j] += paper[i-1][j];
        }
    }

    // for(int i = 0; i <= 10; i++){
    //     for(int j = 0; j <= 10; j++){
    //         cout << paper[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> ans(N+1, 0);
    for(int i = 0; i <= M; i++){
        for(int j = 0; j <= M; j++){
            ans[paper[i][j]]++;
        }
    }

    for(int i = 1; i <= N; i++){
        cout << ans[i] << endl;
    }
    return 0;
}