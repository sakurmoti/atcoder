#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    string S,T; cin >> S >> T;
    int N = S.size();

    for(int w = 1; w < N; w++){
        for(int st = 0; st < w; st++){
            string buf = "";
            for(int i = 0; i < N; i++){
                int idx = st + w*i;
                if(idx < N){
                    buf += S[idx];
                }
            }

            // cout << buf << "\n";
            if(buf == T){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}