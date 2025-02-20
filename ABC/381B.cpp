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
    string S; cin >> S;
    int N = S.size();

    bool flag = true;
    if(N%2 == 1){
        flag = false;
    }

    vector<int> alpha(30, 0);
    for(int i = 0; i < N/2; i++){
        if(S[2*i] != S[2*i+1]){
            flag = false;
        }

        alpha[S[2*i]-'a']++;
        alpha[S[2*i+1]-'a']++;
    }

    for(int i = 0; i < 30; i++){
        if(!(alpha[i] == 0 || alpha[i] == 2)){
            flag = false;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}