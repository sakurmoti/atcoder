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
    int Q; cin >> Q;

    map<int, int> dict;
    while(Q--){
        int cmd; cin >> cmd;

        if(cmd==1){
            int x; cin >> x;
            dict[x]++;

        }else if(cmd==2){
            int x; cin >> x;
            dict[x]--;

            if(dict[x]==0){
                dict.erase(x);
            }

        }else{
            cout << dict.size() << endl;
        }
    }
    return 0;
}