#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int W,B; cin >> W >> B;
    string S = "wbwbwwbwbwbw";
    string piano = S+S+S+S+S + S+S+S+S+S + S+S+S+S+S;
    string T = piano.substr(0, W+B);

    int w=0,b=0;
    for(int i = 0; i < W+B; i++){
        if(T[i] == 'w') w++;
        else b++;
    }
    // cout << w << b << endl;

    if(w == W && b == B){
        cout << "Yes" << endl;
        return 0;
    }

    for(int i = w+b; i < piano.size(); i++){
        if(piano[i-w-b] == 'w') w--;
        else b--;

        if(piano[i] == 'w') w++;
        else b++;

        if(w == W && b == B){
            cout << "Yes" << endl;
            return 0;
        }

        // cout << w << " " << b << endl;
    }

    cout << "No" << endl;
    return 0;
}