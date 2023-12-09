#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

void console_input(int &N, vector<string> &h, vector<string> &v, vector<vector<int>> &d){
    cin >> N;
    h.resize(N-1);
    for(auto &_v : h) cin >> _v;

    v.resize(N);
    for(auto &_v : v) cin >> _v;

    d.resize(N, vector<int>(N));
    for(auto &_v : d) for(auto &_vv : _v) cin >> _vv;
}

void console_output(string &ans){
    if(ans.size() > 1e5) cerr << "size exceeded" << endl;
    cout << ans << endl;
}

void file_input(int &N, vector<string> &h, vector<string> &v, vector<vector<int>> &d){
    ifstream in("./input.txt");
    cin.rdbuf(in.rdbuf());

    cin >> N;
    h.resize(N-1);
    for(auto &_v : h) cin >> _v;

    v.resize(N);
    for(auto &_v : v) cin >> _v;

    d.resize(N, vector<int>(N));
    for(auto &_v : d) for(auto &_vv : _v) cin >> _vv;
}

void file_output(string &ans){
    ofstream of("./output.txt");
    cout.rdbuf(of.rdbuf());
    cout << ans;
}

class Robot{
public:
    int N;
    vector<vector<int>> d;
    vector<string> h,v;
    string ans;

    Robot(int &_n, vector<vector<int>> &_d, vector<string> &_h, vector<string> &_v) 
    : N(_n), d(_d), h(_h), v(_v) {
        // ansをdfsによって初期化
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        function<void(int,int)> dfs = [&](int y, int x) -> void {
            visited[y][x] = true;

            int dirty = -1;
            int idx = -1;
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if(visited[ny][nx]) continue;

                if( (dy[i] == 0 && v[y][min(x,nx)] == '0') || (dx[i]==0 && h[min(y,ny)][x] == '0') ){
                    if(d[y][x] > dirty){
                        dirty = d[y][x];
                        idx = i;
                    }
                }
            }

            if(idx >= 0){
                ans += dir[idx];
                dfs(y+dy[idx], x+dx[idx]);
                ans += dir[(idx+2)%4];
            }
        };

        dfs(0,0);
    }

    void board_state(){
        ofstream of("./board_state.txt");
        cout.rdbuf(of.rdbuf());
        for(auto &v : d){
            for(auto &u : v){
                cout << u << " ";
            }
            cout << endl;
        }
    }

    void update(){
        return;
    }

private:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    string dir = "RDLU";
};


int main(){
    auto start_time = chrono::system_clock::now();

    int n;
    vector<string> h,v;
    vector<vector<int>> d;
    
    console_input(n,h,v,d);
    // file_input(n,h,v,d);

    Robot robot(n,d,h,v);
    
    double elapsed_time = 0.0;
    while(elapsed_time < 1900.0){
        robot.update();

        auto end_time = chrono::system_clock::now();
        elapsed_time = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
    }

    console_output(robot.ans);
    // file_output(robot.ans);
    return 0;
}