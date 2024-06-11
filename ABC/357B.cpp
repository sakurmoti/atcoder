#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    string S; cin >> S;
    int N = S.size();

    int s=0,l=0;
    for(int i = 0; i < N; i++){
        if('a' <= S[i] && S[i] <= 'z'){
            s++;
        }else{
            l++;
        }
    }

    if(s < l){
        for(int i = 0; i < N; i++){
            if('a' <= S[i] && S[i] <= 'z'){
                cout << (char)(S[i] - 32);
            }else{
                cout << S[i];
            }
        }
    }else{
        for(int i = 0; i < N; i++){
            if('A' <= S[i] && S[i] <= 'Z'){
                cout << char(S[i] + 32);
            }else{
                cout << S[i];
            }
        }
    }
    return 0;
}