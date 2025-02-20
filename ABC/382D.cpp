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
    int N,M; cin >> N >> M;

    vector<int> A(N, 0);
    // for(auto &_v : A) cout << _v << " "; cout << endl;

    vector<vector<int>> ans;
    auto dfs = [&](auto &&self, int idx) -> bool {
        if(idx == N-1){
            for(int i = 10; i <= 20; i++){
                A[idx] = A[idx-1]+i;
                if(A[idx] <= M){
                    ans.push_back(A);
                    // for(auto &_v : A) cout << _v << " "; cout << endl;
                    continue;
                }else if(i==10){
                    return false;
                }

                break;
            }
            return true;
        }

        for(int i = 10; i <= 20; i++){
            A[idx] = A[idx-1]+i;
            bool flag = self(self, idx+1);

            if(!flag){
                if(i==10){
                    return false;
                }
                break;
            }
        }

        return true;
    };

    for(int i = 1; i <= 10; i++){
        A[0] = i;
        bool flag = dfs(dfs, 1);
    }

    cout << ans.size() << endl;
    for(auto &v : ans){
        for(int i = 0; i < N; i++){
            cout << v[i] << " \n"[i==N-1];
        }
    }

    return 0;
}