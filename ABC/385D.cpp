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

#pragma optimize("O3")

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N,M,sx,sy; cin >> N >> M >> sx >> sy;

    unordered_map<ll, set<ll>> row, col;
    for(int i = 0; i < N; i++){
        ll x,y; cin >> x >> y;

        row[y].insert(x);
        col[x].insert(y);
    }

    int ans = 0;
    while(M--){
        char d; ll c; cin >> d >> c;
        // printf("sx = %lld, sy = %lld\n", sx, sy);

        ll nx = sx, ny = sy;
        if(d == 'U'){
            ny += c;
            if(col.contains(sx)){
                auto &v = col[sx];
                auto itr = v.lower_bound(sy);

                vector<pair<ll, ll>> eraseList;
                while(itr != v.end() && *itr <= ny){
                    eraseList.push_back({sx, *itr});

                    ans++;
                    itr++;
                }

                for(auto &[x, y] : eraseList){
                    col[x].erase(y);
                    row[y].erase(x);
                }
            }
        }else if(d == 'D'){
            ny -= c;
            if(col.contains(sx)){
                auto &v = col[sx];
                auto itr = v.lower_bound(ny);

                vector<pair<ll, ll>> eraseList;
                while(itr != v.end() && *itr <= sy){
                    eraseList.push_back({sx, *itr});

                    ans++;
                    itr++;
                }

                for(auto &[x, y] : eraseList){
                    col[x].erase(y);
                    row[y].erase(x);
                }
            }
        }else if(d == 'L'){
            nx -= c;
            if(row.contains(sy)){
                auto &v = row[sy];
                auto itr = v.lower_bound(nx);

                vector<pair<ll, ll>> eraseList;
                while(itr != v.end() && *itr <= sx){
                    eraseList.push_back({*itr, sy});

                    ans++;
                    itr++;
                }

                for(auto &[x, y] : eraseList){
                    col[x].erase(y);
                    row[y].erase(x);
                }
            }
        }else if(d == 'R'){
            nx += c;
            if(row.contains(sy)){
                auto &v = row[sy];
                auto itr = v.lower_bound(sx);

                vector<pair<ll, ll>> eraseList;
                while(itr != v.end() && *itr <= nx){
                    eraseList.push_back({*itr, sy});

                    ans++;
                    itr++;
                }

                for(auto &[x, y] : eraseList){
                    col[x].erase(y);
                    row[y].erase(x);
                }
            }
        }

        sx = nx;
        sy = ny;
    }

    cout << sx << " " << sy << " " << ans << "\n";
    return 0;
}