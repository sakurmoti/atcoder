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
    int N; cin >> N;
    vector<vector<char>> A(N+1, vector<char>(N+1, ' '));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> A[i][j];
        }
    }

    for(int i = 1; i <= N/2; i++){
        // 外からi番目の周をi%4 * 90回転
        // if(i%4 == 0) continue;

        int len = N-i+1 - i + 1;
        vector<vector<char>> cp(len, vector<char>(len, ' '));
        for(int y = 0; y < len; y++){
            cp[y][0] = A[i+y][i];
            cp[y][len-1] = A[i+y][N-i+1];
        }
        for(int x = 0; x < len; x++){
            cp[0][x] = A[i][i+x];
            cp[len-1][x] = A[N-i+1][i+x];
        }

        // for(auto &_v : cp){ for(auto &_vv : _v) cout << _vv; cout << endl; }

        for(int rot = 1; rot <= i%4; rot++){
            // cpの外側の要素rot回を90度回転
            for(int x = 0; x < len-1; x++){
                char tmp = cp[0][x];
                cp[0][x] = cp[len-1-x][0];
                cp[len-1-x][0] = cp[len-1][len-1-x];
                cp[len-1][len-1-x] = cp[x][len-1];
                cp[x][len-1] = tmp;

                // for(auto &_v : cp){ for(auto &_vv : _v) cout << _vv; cout << endl; }
            }

            // for(auto &_v : cp){ for(auto &_vv : _v) cout << _vv; cout << endl; }
        }

        // for(auto &_v : cp){ for(auto &_vv : _v) cout << _vv; cout << endl; }


        for(int y = 0; y < len; y++){
            A[i+y][i] = cp[y][0];
            A[i+y][N-i+1] = cp[y][len-1];
        }

        for(int x = 0; x < len; x++){
            A[i][i+x] = cp[0][x];
            A[N-i+1][i+x] = cp[len-1][x];
        }

    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << A[i][j];
        }
        cout << "\n";
    }
    return 0;
}