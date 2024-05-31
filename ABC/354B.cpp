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
    map<string, int> dict;
    ll sum = 0;
    for(int i = 0; i < N; i++){
        string s;
        int c;
        cin >> s >> c;
        dict[s] = 0;
        sum += c;
        sum %= N;
    }

    int idx = 0;
    for(auto [k,v] : dict){
        if(idx == sum){
            cout << k << endl;
            return 0;
        }
        idx++;
    }
    
    return 0;
}