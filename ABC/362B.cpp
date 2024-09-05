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
    vector<pair<int, int>> v(3);
    for(int i = 0; i < 3; i++){
        cin >> v[i].first >> v[i].second;
    }

    auto dist = [](pair<int, int> a, pair<int, int> b){
        return (a.first - b.first)*(a.first-b.first) + (a.second - b.second)*(a.second - b.second);
    };

    sort(ALL(v));
    do{
        int a = dist(v[0], v[1]);
        int b = dist(v[0], v[2]);
        int c = dist(v[1], v[2]);

        if(a + b == c){
            cout << "Yes" << endl;
            return 0;
        }

    }while(next_permutation(ALL(v)));
    
    cout << "No" << endl;
    return 0;
}