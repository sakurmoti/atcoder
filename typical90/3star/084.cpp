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
    string S; cin >> S;
    S.insert(S.begin(), ' ');

    vector<int> osum(N+1, 0), xsum(N+1, 0);
    for(int i = 1; i <= N; i++){
        char c = S[i];
        osum[i] += osum[i-1] + (c == 'o');
        xsum[i] += xsum[i-1] + (c == 'x');
    }

    ll ans = 0;
    for(int i = 1; i <= N; i++){
        int idx;
        if(S[i] == 'o'){
            // xsum[k] - xsum[i-1] := [i, k]の総和
            // これが1以上になる最小のidxを探せばその後は全て満たす
            idx = upper_bound(ALL(xsum), xsum[i]) - xsum.begin();
            ans += (N-idx+1);
        }else{
            idx = upper_bound(ALL(osum), osum[i]) - osum.begin();
            ans += (N-idx+1);
        }
        // cout << idx << endl;
    }

    cout << ans << endl;
    return 0;
}