#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

struct Point{int x,y;};
struct Area{Point Lu,Ld,Ru,Rd; int id;}; // 四隅の座標のみ管理
struct Judge{
    vector<vector<Area>> ans; // ans[d][k] := d日目のk番目の予約の長方形
    Judge(){}

    void add(int d, vector<Area> a){
        ans.push_back(a);
    }

    void output(){
        for(auto u : ans){
            for(auto v : u){
                cout << v.Lu.y << " " << v.Lu.x << " " << v.Rd.y << " " << v.Rd.x << endl;
            }
            cout << endl;
        }
    }

};

struct Partitions{
    int W;
    vector<vector<int>> grid;

    Partitions(int _w) : W(_w){
        grid.resize(W, vector<int>(W,0));
    }

    void put(Area a){
        for(int y = a.Lu.y; y < a.Rd.y; y++){
            for(int x = a.Lu.x; x < a.Rd.x; x++){
                grid[y][x] = a.id;
            }
        }
    }

    bool is_put(Area a){
        for(int y = a.Lu.y; y < a.Rd.y; y++){
            for(int x = a.Lu.x; x < a.Rd.x; x++){
                if(grid[y][x] > 0) return false;
            }
        }
        return true;
    }

    void output(){
        cout << "# Partitions\n";
        for(int i = 0; i < W; i++){
            for(int j = 0; j < W; j++){
                cout << grid[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
};

struct Solver{
    int W,D,N;
    vector<vector<int>> Reserve;
    
    Judge judge;

    Solver(int _w, int _d, int _n, vector<vector<int>> _a)
        : W(_w), D(_d), N(_n), Reserve(_a){
        }

    void solve(){


    }

};

void solve(string seed = ""){
    #ifndef ONLINE_JUDGE
        ifstream ifs("input/" + seed + ".txt");
        cin.rdbuf(ifs.rdbuf());
        ofstream ofs("output/" + seed + ".txt");
        cout.rdbuf(ofs.rdbuf());

        auto start = chrono::system_clock::now();
    #endif
    
    int w,d,n;
    cin >> w >> d >> n;
    vector<vector<int>> a(d, vector<int>(n));
    for(int i = 0; i < d; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    Solver solver(w,d,n,a);
    solver.solve();

    #ifndef ONLINE_JUDGE
        auto end = chrono::system_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        cerr << "seed : " << seed << ", ";
        cerr << "time : " << elapsed << "\n";
    #endif
}

int main(){
    #ifndef ONLINE_JUDGE
        for(int i = 0; i < 100; i++){
            stringstream ss;
            ss << setw(4) << setfill('0') << i;
            solve(ss.str());
        }
    #else
        solve();
    #endif

    return 0;
}