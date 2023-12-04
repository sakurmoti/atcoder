#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<string> S(N);
    for(auto &_v : S) cin >> _v;

    // L字が何個できるか
    // 直角の頂点を全探索

    vector<int> column(N, 0);
    vector<int> row(N, 0);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(S[i][j] == 'o'){
                row[i]++;
                column[j]++;
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(S[i][j] == 'o'){
                // このi,jを直角の頂点としたときにできるL字の個数
                // (i,j)を除いた同じ行と列の組合せ
                ans += (row[i]-1) * (column[j] - 1);
            }
        }
    }

    cout << ans << endl;
    return 0;
}