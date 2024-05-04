#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> dp(N+1, vector<int>(N+1, 1e9));
    dp[1][1] = 0;

    queue<pair<int, int>> que;
    que.push(make_pair(1,1));
    vector<vector<bool>> visited(N+1, vector<bool>(N+1, false));
    
    while(!que.empty()){
        auto [k,l] = que.front();
        que.pop();

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(visited[i][j]) continue;

                if((i-k)*(i-k) + (j-l)*(j-l) == M){
                    que.push(make_pair(i,j));
                    dp[i][j] = dp[k][l] + 1;
                }
            }
        }

        visited[k][l] = true;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(visited[i][j]) cout << dp[i][j] << " ";
            else cout << -1 << " ";
        }
        cout << endl;
    }
    return 0;
}