#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int N,M;
vector<int> A,B;
vector<vector<int>> memo;
// 山Aがa番目、山Bがb番目のとき最大の価値
int dfs(int a, int b, int sum){
    if(memo[a][b] != -1) return memo[a][b];

    int score = 0;
    if(a < N){
        chmax(score, sum - dfs(a+1, b, sum-A[a]));
    }

    if(b < M){
        chmax(score, sum - dfs(a, b+1, sum-B[b]));
    }

    memo[a][b] = score;
    // printf("memo[%d][%d] = %d\n",a,b,memo[a][b]);
    return score;
}

int main(){
    cin >> N >> M;
    A.resize(N); B.resize(M);
    for(auto &_v : A) cin >> _v;
    for(auto &_v : B) cin >> _v;

    int sum = 0;
    for(auto u : A) sum += u;
    for(auto u : B) sum += u;
    memo.resize(N+1, vector<int>(M+1, -1));

    dfs(0,0,sum);
    cout << memo[0][0] << endl;
    return 0;
}