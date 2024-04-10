#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<string> S(N);
    for(auto &_v : S) cin >> _v;

    vector<int> column(N,0),row(N,0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(S[i][j] == 'o'){
                column[i]++;
                row[j]++;
            }
        }
    }

    // for(auto &_v : column) cout << _v << " "; cout << endl;
    // for(auto &_v : row) cout << _v << " "; cout << endl;

    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(S[i][j] == 'o'){
                ans += (column[i]-1)*(row[j]-1);
            }
        }
    }

    cout << ans << endl;
    return 0;
}