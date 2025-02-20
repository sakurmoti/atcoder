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
    string S; cin >> S;

    vector<int> slash;
    for(int i = 0; i < N; i++){
        if(S[i] == '/') slash.push_back(i);
    }

    int ans = 0;
    if(slash.size() != 0){
        ans = 1;
    }
    for(int i = 0; i < slash.size(); i++){
        for(int j = 1; j < N; j++){
            if(slash[i]-j >= 0 && slash[i]+j < N && S[slash[i]-j] == '1' && S[slash[i]+j] == '2'){
                continue;
            }

            chmax(ans, 2*j-1);
            break;
        }
    }

    cout << ans << endl;
    return 0;
}