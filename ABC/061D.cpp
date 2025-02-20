#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll N,M; cin >> N >> M;
    
    vector<tuple<ll,ll,ll>> edges(M);
    for(int i = 0; i < M; i++){
        ll a,b,c; cin >> a >> b >> c;
        edges[i] = make_tuple(a,b,c);
    }

    vector<ll> dist(N+1, -9e18);
    dist[1] = 0;

    for(int limit = 1; limit <= N; limit++){
        
        for(int i = 0; i < M; i++){
            auto[now, nex, cost] = edges[i];
            
            // cout << now << endl;
            if(dist[now] < -9e17) continue;
            
            if(dist[now] + cost > dist[nex]){
                dist[nex] = dist[now] + cost;
                
                // N回目に更新があれば閉路あり
                if(limit == N){
                    // 閉路を1からNまでのパスに含めることができるか
                    auto bfs = [&](int from, int to) -> bool {
                        if(from == to) return true;

                        vector<bool> visited(N+1, false);
                        queue<int> que;
                        que.push(from);
                        while(!que.empty()){
                            int v = que.front(); que.pop();
                            if(visited[v]) continue;
                            visited[v] = true;

                            for(int i = 0; i < M; i++){
                                auto[now, nex, cost] = edges[i];
                                if(now == v) que.push(nex);
                            }
                        }
                        return visited[to];
                    };
                    
                    // 1からnowまでのパスがあるか
                    bool from1 = bfs(1, now);

                    // nowからNまでのパスがあるか
                    bool toN = bfs(now, N);
                    
                    if(from1 && toN){
                        cout << "inf" << endl;
                        return 0;
                    }
                }
            }
        }

    }

    cout << dist[N] << endl;
    return 0;
}