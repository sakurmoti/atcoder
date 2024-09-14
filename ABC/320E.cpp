#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x, y;};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,M; cin >> N >> M;
    vector<ll> A(N, 0);
    priority_queue<int, vector<int>, greater<int>> que;
    for(int i = 0; i < N; i++) que.push(i);
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pque;

    while(M--){
        ll T,W,S; cin >> T >> W >> S;

        while(!pque.empty()){
            auto[t,id] = pque.top();
            if(t > T) break;

            pque.pop();
            que.push(id);
        }

        if(que.empty()) continue;

        int id = que.top();
        que.pop();
        // printf("id=%d\n",id);

        A[id] += W;
        pque.push(make_pair(T+S, id));
    }

    for(auto &_v : A) cout << _v << " "; cout << endl;
    return 0;
}