#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

struct Box{
    int exitId,exitNo;
    int x,y;

    Box(){}
    Box(int id, int no):exitId(id),exitNo(no){
        x = id;
        y = no;
    }

    pair<int, int> getExitInfo(){
        return make_pair(exitId, exitNo);
    }
};

struct Judge{
    void input(int &n, vector<vector<Box>> &a){
        cin >> n;
        a.resize(n, vector<Box>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int b; cin >> b;
                a[i][j] = Box(b/n, b%n);
            }
        }
    }

    void output(vector<string> &ans){
        for(auto &u : ans) cout << u << endl;
    }

    /// @param move 移動の履歴
    /// @param outBox 搬出口のコンテナ
    tuple<int, int, int, int> getScore(vector<string> &move, vector<vector<Box>> &outBox){
        int N = 5;
        int M0=-1,M1=-1,M2=-1,M3=-1;

        // 最も長い文字列が最長ターン
        for(auto &s : move){
            chmax(M0, (int)s.size());
        }

        // 搬出されなかったコンテナの総数
        int all = N*N;
        int outer = 0;
        for(int i = 0; i < outBox.size(); i++){
            outer += (int)outBox[i].size();
        }
        M3 = all - outer;

        // 搬出口を間違えたコンテナ
        vector<vector<int>> correct(N); // M1用の正しい搬出口
        for(int i = 0; i < outBox.size(); i++){
            for(int j = 0; j < outBox[i].size(); j++){
                auto[id,no] = outBox[i][j].getExitInfo();
                if(i != id){
                    M2++;
                }else{
                    correct[i].push_back(no);
                }
            }
        }

        // 転倒数をバブルソートで
        for(int i = 0; i < N; i++){
            for(int j = 0; j < correct[i].size(); j++){
                for(int k = j; k < correct[i].size() - j; k++){
                    if(correct[k] > correct[k+1]){
                        swap(correct[k], correct[k+1]);
                        M1++;
                    }
                }
            }
        }
        
        return make_tuple(M0,M1,M2,M3);
    }
};

struct Solver{
    int N;
    vector<vector<Box>> A;
    vector<string> move;
    vector<vector<Box>> outBox;
    Judge judge;

    Solver(){
        judge.input(N,A);
        move.resize(N);
    }

    void solve(){
        for(int j = 1; j < N; j++){
            move[j] += "B"; // 簡単のため、子クレーンを全て爆破
        }

        auto fixed_y = [&](int id, int y){
            if(id - y > 0){
                return string(id-y, 'D');
            }else{
                return string(y-id, 'U');
            }
        };

        auto rev_fixed_y = [&](int id, int y){
            if(id - y > 0){
                return string(id-y, 'U');
            }else{
                return string(y-id, 'D');
            }
        };

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                auto[id,no] = A[i][j].getExitInfo();
                move[0] += "P" + fixed_y(id, i) + string(N-1, 'R') + "Q";
                
                if(! (i==N-1 && j==N-1) ) move[0] += rev_fixed_y(id, i) + string(N-1, 'L');
            }
            if(i!=N-1) move[0] += "D";
        }
        
        judge.output(move);
        
    }
};

int main(){
    #ifdef __LOCAL__
        for(int seed = 0; seed < 100; seed++){
            stringstream ss;
            ss << setfill('0') << setw(4) << seed;
            ifstream ifs("input/" + ss.str() + ".txt");
            cin.rdbuf(ifs.rdbuf());
            ofstream ofs("output/" + ss.str() + ".txt");
            cout.rdbuf(ofs.rdbuf());

            Solver solver;
            solver.solve();
        }
    #else
        Solver solver;
        solver.solve();
    #endif

    return 0;
}