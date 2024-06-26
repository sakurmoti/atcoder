#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

#include <atcoder/all>
using namespace atcoder;

int main(){
    int H,W; cin >> H >> W;
    int Q; cin >> Q;

    dsu d(H*W);
    vector<vector<char>> field(H, vector<char>(W, 'w'));
    constexpr int dx[4] = {0,1,0,-1};
    constexpr int dy[4] = {1,0,-1,0};
    while(Q--){
        int t; cin >> t;

        if(t==1){
            int r,c; cin >> r >> c;
            r--; c--;
            field[r][c] = 'r';
            for(int i = 0; i < 4; i++){
                int nr = r + dy[i];
                int nc = c + dx[i];

                if(isRange(nr,0,H) && isRange(nc,0,W) && field[nr][nc] == 'r'){
                    d.merge(r*W+c, nr*W+nc);
                }
            }

        }else{
            int r1,c1,r2,c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--; c1--;
            r2--; c2--;

            if(field[r1][c1] == field[r2][c2] && field[r1][c1] == 'r' && d.same(r1*W+c1, r2*W+c2)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}