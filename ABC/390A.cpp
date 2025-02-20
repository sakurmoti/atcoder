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
    vector<int> A(5);
    for(auto &_v : A) cin >> _v;

    int cnt = 0;
    for(int i = 0; i < 5; i++){
        for(int j = i+1; j < 5; j++){
            if(A[i] > A[j]){
                cnt++;
                swap(A[i], A[j]);
            }
        }
    }

    if(cnt==1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}