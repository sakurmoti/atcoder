#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    vector<pair<int, int>> color(N, {-1,-1});

    for(int i = 0; i < 2*N; i++){
        int a; cin >> a;
        a--;
        if(color[a].first >= 0){
            color[a].second = i;
        }else{
            color[a].first = i;
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(abs(color[i].second - color[i].first) == 2){
            // cout << i << endl;
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}