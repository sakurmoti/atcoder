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

void debug(string S){ cout << "# " << S << endl; }

struct Solver{
    struct Judge{
        static void move(int v){cout << "m " << v << endl;}
        static void set(int l, int a, int b){cout << "s " << l << " " << a << " " << b << endl;}
    };

    int N,M,T,lenA,lenB;
    vector<vector<int>> G;
    vector<int> target;
    vector<Point> P;

    vector<int> A;
    random_device rd;
    mt19937 gen;
                    
    Solver(int n, int m, int t, int la, int lb, vector<vector<int>> g, vector<int> tar, vector<Point> p) 
        : N(n), M(m), T(t), lenA(la), lenB(lb), G(g), target(tar), P(p){
            A.resize(lenA, 0);
            gen = mt19937(rd());
        }
    
    // どの経路で行くか探索
    // パスは始点を含まず、終点を含む
    vector<vector<int>> find_path(){
        auto bfs = [&](int st, int gl){
            queue<int> que;
            que.push(st);
            vector<bool> visited(N, false);
            visited[st] = true;
            vector<int> parent(N, -1);

            while(!que.empty()){
                int v = que.front();
                que.pop();

                if(v==gl){
                    vector<int> path;
                    while(parent[v] != -1){
                        path.push_back(v);
                        v = parent[v];
                    }
                    reverse(ALL(path));
                    return path;
                }

                for(int i = 0; i < G[v].size(); i++){
                    int next = G[v][i];
                    if(visited[next]) continue;
                    visited[next] = true;

                    parent[next] = v;
                    que.push(next);    
                }
            }

            throw runtime_error("no path : " + to_string(st) + " -> " + to_string(gl));
        };

        vector<vector<int>> paths(T);
        int now = 0;
        for(int i = 0; i < T; i++){
            vector<int> path = bfs(now, target[i]);
            now = target[i];
            paths[i] = path;
        }

        return paths;
    }

    void make_A(vector<vector<int>> &paths){
        // 使用回数が0の頂点を削る
        vector<int> used;
        vector<bool> isAdd(N, false);
        for(int i = 0; i < T; i++){
            for(auto &v : paths[i]){
                if(!isAdd[v]){
                    used.push_back(v);
                    isAdd[v]=true;
                }
            }
        }

        
        // Aの構築
        for(int i = 0; i < lenA; i++){
            A[i] = used[i%used.size()];
        }

        for(auto &_v : A) cout << _v << " "; cout << endl;
    }

    // パスをどのように辿るかをin-placeで行う
    void output(vector<vector<int>> &paths){
        vector<int> B(lenB, -1);
        for(int i = 0; i < T; i++){
            for(int j = 0; j < paths[i].size(); j++){
                int next = paths[i][j];
                bool isContains = false;
                for(int k = 0; k < lenB; k++){
                    if(next == B[k]) isContains = true;
                }

                if(isContains){
                    Judge::move(next);
                }else{
                    // Bの再構築
                    // Aの中から該当頂点を探す
                    int x = -1;
                    for(int k = 0; k < lenA; k++){
                        if(A[k] == next){
                            x = k;
                            break;
                        }
                    }
                    int l = min(lenB, lenA-x);
                    for(int k = 0; k < l; k++){
                        B[k] = A[(x+k)%lenA];
                    }

                    Judge::set(lenB, x, 0);
                    Judge::move(next);
                    debug("move " + to_string(next));
                }

                
            }
        }
    }

    void solve(){
        vector<vector<int>> result = find_path();
        make_A(result);
        output(result);
    }
};

void input(
    int &N, int &M, int &T, int &La, int &Lb,
    vector<vector<int>> &G, vector<int> &target, vector<Point> P){

    cin >> N >> M >> T >> La >> Lb;
    G.assign(N, vector<int>());
    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    target.assign(T, 0);
    for(auto &_v : target) cin >> _v;

    P.assign(N, Point());
    for(int i = 0; i < N; i++){
        cin >> P[i].x >> P[i].y;
    }
}

int main(){
    int N,M,T,La,Lb;
    vector<vector<int>> G;
    vector<int> target;
    vector<Point> P;

    #ifndef ONLINE_JUDGE
        streambuf *cinbuf = cin.rdbuf();
        streambuf *coutbuf = cout.rdbuf();
        for(int seed = 0; seed < 20; seed++){
            auto start = chrono::system_clock::now();
            
            stringstream ss;
            ss << setw(4) << setfill('0') << seed;
            ifstream ifs("in/" + ss.str() + ".txt");
            cin.rdbuf(ifs.rdbuf());
            ofstream ofs("out/" + ss.str() + ".txt");
            cout.rdbuf(ofs.rdbuf());

            input(N,M,T,La,Lb,G,target,P);
            Solver sol(N,M,T,La,Lb,G,target,P);
            sol.solve();

            auto end = chrono::system_clock::now();
            auto msec = chrono::duration_cast<chrono::milliseconds>(end-start).count();
            cerr << "seed: " << seed << " finished in " << msec << "ms\n";
        }
        cin.rdbuf(cinbuf);
        cout.rdbuf(coutbuf);
    #else
        input(N,M,T,La,Lb,G,target,P);
        Solver sol(N,M,T,La,Lb,G,target,P);
        sol.solve();
    #endif
}