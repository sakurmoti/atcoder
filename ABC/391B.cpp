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

int main(){
    int N,M; cin >> N >> M;
    vector<string> S(N),T(M);
    for(auto &_v : S) cin >> _v;
    for(auto &_v : T) cin >> _v;

    for(int si = 0; si < N; si++){
        for(int sj = 0; sj < N; sj++){
            bool flag = true;
            for(int i = 0; i < M; i++){
                for(int j = 0; j < M; j++){
                    if(isRange(si+M-1, 0, N) && isRange(sj+M-1, 0, N)){
                        if(S[si+i][sj+j] != T[i][j]){
                            flag = false;
                        }

                    }else{
                        flag = false;
                    }
                }
            }

            if(flag){
                cout << si+1 << " " << sj+1 << endl;
                return 0;
            }
        }
    }
    return 0;
}