#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    string S,T,U; cin >> S >> T >> U;
    int A=0,B=0,C=0;

    char now = 'a';
    while(true){
        if(now == 'a'){
            if(A == S.size()){
                cout << 'A' << endl;
                return 0;
            }
            now = S[A];
            A++;

        }else if(now == 'b'){
            if(B == T.size()){
                cout << 'B' << endl;
                return 0;
            }
            now = T[B];
            B++;

        }else{
            if(C == U.size()){
                cout << 'C' << endl;
                return 0;
            }
            now = U[C];
            C++;
            
        }
    }
    return 0;
}