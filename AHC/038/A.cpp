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


void greedy(){
    int N,M,V;
    cin >> N >> M >> V;
    vector<string> S(N),T(N);
    for(auto &_v : S) cin >> _v;
    for(auto &_v : T) cin >> _v;

    vector<Point> s,t;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(S[i][j] == '1' && T[i][j] == '1') continue;
            if(S[i][j] == '1') s.push_back(Point(j, i));
            if(T[i][j] == '1') t.push_back(Point(j, i));
        }
    }
    if(s.size() != t.size()){
        cerr << "s.size() != t.size()" << endl;
        return;
    }

    M = s.size();

    // 2頂点を横に長さ1で結んだ木を作る
    cout << 2 << endl;
    cout << 0 << " " << 1 << endl; // parを0, rを1とする葉の追加
    cout << 0 << " " << 0 << endl;

    vector<int> match; // s[i]とt[match[i]]が対応
    vector<bool> used(M, false); //t[i]を使用したか
    for(int i = 0; i < M; i++){
        int min_dist = 1e9;
        int cor = -1;
        for(int j = 0; j < M; j++){
            if(used[j]) continue;

            int dist = abs(s[i].x - t[j].x) + abs(s[i].y - t[j].y);
            if(chmin(min_dist, dist)){
                cor = j;
            }
        }
        used[cor] = true;
        if(min_dist!=0) match.push_back(cor);
    }

    used.assign(M, false); // s[i] と t[match[i]]のペアが置き終わったか
    vector<int> uncomplete;
    Point now = Point(1, 0); // 葉の座標
    for(int i = 0; i < M; i++){
        // 未使用のs[j]のうち、nowに最も近いものを探す
        int min_dist = 1e9;
        int next = -1;
        for(int j = 0; j < M; j++){
            if(used[j]) continue;
            int dist = abs(now.x - s[j].x) + abs(now.y - s[j].y); // 葉からs[j]への距離
            if(chmin(min_dist, dist)){
                next = j;
            }
        }
        
        // cerr << "now : " << now.x << " " << now.y << endl;
        // cerr << "next : " << s[next].x << " " << s[next].y << endl;

        // 端はrootが外に出てしまうので一度飛ばす
        if(s[next].x == 0 || t[match[next]].x == 0){
            used[next] = true;
            uncomplete.push_back(next);
            continue;
        }

        // nowからs[next]への移動し、たこ焼きをつかむ
        int dx = s[next].x - now.x;
        int dy = s[next].y - now.y;
        for(int i = 0; i < abs(dx); i++){
            if(dx > 0) cout << "R";
            else cout << "L";

            cout << "...\n";
        }
        for(int i = 0; i < abs(dy); i++){
            if(dy > 0) cout << "D";
            else cout << "U";

            cout << "...\n";
        }
        cout << "...P\n";

        // s[next]からt[match[next]]への移動し、たこ焼きを置く
        dx = t[match[next]].x - s[next].x;
        dy = t[match[next]].y - s[next].y;
        for(int i = 0; i < abs(dx); i++){
            if(dx > 0) cout << "R";
            else cout << "L";

            cout << "...\n";
        }
        for(int i = 0; i < abs(dy); i++){
            if(dy > 0) cout << "D";
            else cout << "U";

            cout << "...\n";
        }
        cout << "...P\n";

        used[next] = true;
        now = t[match[next]];
    }

    // 未完了のペアを処理するために反転
    cout << ".L..\n";
    cout << ".L..\n";
    now = Point(now.x-2, now.y);

    for(int i = 0; i < uncomplete.size(); i++){
        int next = uncomplete[i];
        // cerr << "now : " << now.x << " " << now.y << endl;
        // cerr << "next : " << s[next].x << " " << s[next].y << endl;

        // nowからs[next]への移動し、たこ焼きをつかむ
        int dx = s[next].x - now.x;
        int dy = s[next].y - now.y;
        for(int i = 0; i < abs(dx); i++){
            if(dx > 0) cout << "R";
            else cout << "L";

            cout << "...\n";
        }
        for(int i = 0; i < abs(dy); i++){
            if(dy > 0) cout << "D";
            else cout << "U";

            cout << "...\n";
        }
        cout << "...P\n";

        // s[next]からt[match[next]]への移動し、たこ焼きを置く
        dx = t[match[next]].x - s[next].x;
        dy = t[match[next]].y - s[next].y;
        for(int i = 0; i < abs(dx); i++){
            if(dx > 0) cout << "R";
            else cout << "L";

            cout << "...\n";
        }
        for(int i = 0; i < abs(dy); i++){
            if(dy > 0) cout << "D";
            else cout << "U";

            cout << "...\n";
        }
        cout << "...P\n";

        used[next] = true;
        now = t[match[next]];

    }
}

struct Tree{
    struct Node{
        Point p;
        int par = -1; //親のidx
        int r = -1; // 辺の長さ
        bool isLeaf=true;

        Node(Point _p) : p(_p){}
        Node(int _par, int _r) : par(_par), r(_r) {p = Point(0, r);}
    };

    vector<Node> nodes;
    Tree(){
        nodes.push_back(Node(Point(0,0)));
    }

    void addNode(int par, int r){
        nodes.push_back(Node(par, r));
        nodes[par].isLeaf = false;
    }

    void print(){
        int N = nodes.size();
        cout << N << "\n";
        for(int i = 1; i < N; i++){
            cout << nodes[i].par << " " << nodes[i].r << "\n";
        }
        cout << nodes[0].p.y << " " << nodes[0].p.x << "\n";
    }
};

struct Solver{
    int N,M,V;
    vector<Point> S,T;
    Tree tree;

    Solver(int n, int m, int v, vector<string> s, vector<string> t) 
    : N(n), M(m), V(v){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(s[i][j] == '1') S.push_back(Point(j, i));
                if(t[i][j] == '1') T.push_back(Point(j, i));
            }
        }
    }

    void solve(){
        tree.addNode(0, 1);


    }
};

void input(int &n, int &m, int &v, vector<string> &s, vector<string> &t){
    cin >> n >> m >> v;
    
    s.assign(n, "");
    t.assign(n, "");
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
}

int main(){
    int N,M,V;
    vector<string> S,T;

    #ifndef ONLINE_JUDGE
        streambuf *cinbuf = cin.rdbuf();
        streambuf *coutbuf = cout.rdbuf();
        for(int seed = 0; seed < 100; seed++){
            auto start = chrono::system_clock::now();
            
            stringstream ss;
            ss << setw(4) << setfill('0') << seed;
            ifstream ifs("in/" + ss.str() + ".txt");
            cin.rdbuf(ifs.rdbuf());
            ofstream ofs("out/" + ss.str() + ".txt");
            cout.rdbuf(ofs.rdbuf());

            // input(N,M,V,S,T);
            // Solver sol(N,M,V,S,T);
            // sol.solve();

            greedy();

            auto end = chrono::system_clock::now();
            auto msec = chrono::duration_cast<chrono::milliseconds>(end-start).count();
            cerr << "seed: " << seed << " finished in " << msec << "ms\n";
        }
        cin.rdbuf(cinbuf);
        cout.rdbuf(coutbuf);
    #else
        input(N,M,V,S,T);
        Solver sol(N,M,V,S,T);
        sol.solve();
    #endif
}