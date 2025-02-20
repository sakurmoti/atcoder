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
    int H,W; cin >> H >> W;
    ll X; cin >> X;
    int P,Q; cin >> P >> Q;
    P--; Q--;
    vector<vector<ll>> A(H, vector<ll>(W));
    for(auto &_v : A) for(auto &_vv : _v) cin >> _vv;

    using origin = pair<ll, pair<int,int>>;
    priority_queue<origin, vector<origin>, greater<origin>> pque;
    set<pair<int,int>> visited;
    
    for(int i = 0; i < 4; i++){
        int nx = Q+dx[i];
        int ny = P+dy[i];
        if(isRange(nx, 0, W) && isRange(ny, 0, H)){
            pque.push(make_pair(A[ny][nx], make_pair(nx, ny)));
        }
    }

    ll Takahashi = A[P][Q];
    visited.insert(pair<int,int>(Q, P));
    while(!pque.empty()){
        auto[v, p] = pque.top(); pque.pop();
        if(visited.contains(p)) continue;
        visited.insert(p);

        // printf("now: [%d,%d] T = %lld\n", p.first, p.second, Takahashi);

        if(Takahashi > A[p.second][p.first] * X){
            Takahashi += A[p.second][p.first];

            for(int i = 0; i < 4; i++){
                int nx = p.first+dx[i];
                int ny = p.second+dy[i];
                if(isRange(nx, 0, W) && isRange(ny, 0, H)){
                    pque.push(make_pair(A[ny][nx], make_pair(nx, ny)));
                }
            }
        
        }else{
            break;
        }
    }

    cout << Takahashi << endl;
    return 0;
}