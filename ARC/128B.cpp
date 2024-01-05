#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int T; cin >> T;

    // 3つのうち2つが同じ個数になれば可能
    // 選んだ2つをX,Y(X <= Y), 残り1つをZとすれば
    // YとZをXに変換してX==Yにできるかどうか
    auto solve = [](ll X, ll Y, ll Z) -> ll {
        if(X > Y) swap(X,Y);

        // 変換するときYは1つ減り、Xは2つ増える
        // X==Y==0 (mod 3)になればよい
        if(X%3 != Y%3) return 1e18;

        // YとZを1個使ってXを2個錬成
        ll dist = (Y-X)/3;

        // dist回で X+2dist == Yになる
        return dist + (X + 2*dist);
    };

    while(T--){
        ll R,G,B;
        cin >> R >> G >> B;

        ll ans = 1e18;

        // R==Gの場合
        ans = min(ans, solve(R,G, B));

        // R==Bの場合
        ans = min(ans, solve(R,B, G));

        // G==Bの場合
        ans = min(ans, solve(G,B, R));

        if(ans > 1e17) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}