#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,M;
    cin >> N >> M;

    // (k-i)^2 + (l-j)^2 = Mである必要がある
    // x = (k-i), y = (l-j)とおく
    vector<pair<int, int>> dxy;
    for(int x = 0; x*x <= M; x++){
        int y = (int)sqrt(M - x*x);
        if(x*x + y*y == M){
            dxy.push_back(make_pair(x,y));
            dxy.push_back(make_pair(x,-y));
            dxy.push_back(make_pair(-x,y));
            dxy.push_back(make_pair(-x,-y));
        }
    }

    queue<tuple<int, int, int>> que;
    que.push(make_tuple(0,0,0));
    vector<vector<int>> ans(N, vector<int>(N, -1));

    while(!que.empty()){
        auto[y,x,d] = que.front();
        que.pop();

        if(ans[y][x] >= 0) continue;
        ans[y][x] = d;

        for(auto [dx,dy] : dxy){
            int k = x + dx;
            int l = y + dy;

            // printf("(%d, %d) -> (%d, %d)\n",x,y,k,l);
            if(isRange(k,0,N) && isRange(l,0,N) && ans[l][k] < 0){
                que.push(make_tuple(l,k,d+1));
            }
        }
    }

    for(auto &_v : ans){ for(auto &_vv : _v) cout << _vv << " "; cout << endl; }
    return 0;
}