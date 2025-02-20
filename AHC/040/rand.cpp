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
    int N,T,sd; cin >> N >> T >> sd;
    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++){
        int w,h; cin >> w >> h;
        A[i] = {w,h};
    }

    // 全てx=0の縦に積む場合
    T--;
    cout << N << endl;
    for(int i = 0; i < N; i++){
        cout << i << " 0 U -1" << endl;
    }
    int bufx, bufy;
    cin >> bufx >> bufy;

    // 全てy=0の横に積む場合
    T--;
    cout << N << endl;
    for(int i = 0; i < N; i++){
        cout << i << " 0 L -1" << endl;
    }
    cin >> bufx >> bufy;

    while(T--){
        cout << 0 << endl;
        cin >> bufx >> bufy;
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