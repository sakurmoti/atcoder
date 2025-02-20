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

void solve(){
    int N,M,H; cin >> N >> M >> H;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; ++i){
        int u,v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; ++i){
        int x,y; cin >> x >> y;
        P[i] = make_pair(x,y);
    }

    vector<int> leader(N, -1);
    for(int i = 0; i < N; i++){
        if(leader[i] != -1) continue;

        queue<tuple<int, int, int>> que;
        que.push(make_tuple(i, i, 0));
        while(!que.empty()){
            auto [v, l, d] = que.front(); que.pop();
            if(leader[v] != -1 || d > H) continue;
            leader[v] = l;

            for(auto nv : G[v]){
                que.push(make_tuple(nv, v, d+1));
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(leader[i] == i){
            cout << -1 << " ";
        }else{
            cout << leader[i] << " ";
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
        streambuf *cinbuf = cin.rdbuf();
        streambuf *coutbuf = cout.rdbuf();
        for(int seed = 0; seed < 10; seed++){
            stringstream ss;
            ss << setw(4) << setfill('0') << seed;
            ifstream ifs("in/" + ss.str() + ".txt");
            ofstream ofs("out/" + ss.str() + ".txt");
            cin.rdbuf(ifs.rdbuf());
            cout.rdbuf(ofs.rdbuf());

            auto start = chrono::system_clock::now();
            solve();
            auto end = chrono::system_clock::now();
            auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
            cerr << "elapsed: " << elapsed << "ms" << endl;

            cin.rdbuf(cinbuf);
            cout.rdbuf(coutbuf);
        }
        return 0;
    #endif

    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    solve();
    return 0;
}