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
    string S,T; cin >> S >> T;
    int N = S.size();
    
    vector<int> comp(N, 0);
    for(int i = 0; i < N; i++){
        if(S[i] > T[i]){
            comp[i] = -1;
        }else if(S[i] == T[i]){
            comp[i] = 0;
        }else{
            comp[i] = 1;
        }
    }

    vector<string> ans;
    ans.push_back(S);
    int size = 0;
    for(int i = 0; i < N; i++){
        if(comp[i] < 0){
            string cpy = ans[size];
            cpy[i] = T[i];
            ans.push_back(cpy);
            size++;
        }
    }

    for(int i = N-1; i >= 0; i--){
        if(comp[i] > 0){
            string cpy = ans[size];
            cpy[i] = T[i];
            ans.push_back(cpy);
            size++;
        }
    }

    cout << size << endl;
    for(int i = 1; i <= size; i++){
        cout << ans[i] << endl;
    }
    return 0;
}