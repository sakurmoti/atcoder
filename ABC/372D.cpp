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
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    vector<int> ans(N,0);
    stack<int> stk;
    
    for(int i = N-2; i >= 0; i--){
        // cout << A[i+1] << " : ";
        while(!stk.empty() && stk.top() < A[i+1]){
            // cout << stk.top() << " ";
            stk.pop();
        }
        // cout << endl;
        stk.push(A[i+1]);

        ans[i] = stk.size();
    }

    for(auto &_v : ans) cout << _v << " "; cout << endl;
    return 0;
}