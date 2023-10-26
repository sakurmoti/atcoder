#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> X(M);
    for(auto &_v : X) cin >> _v;

    if(N >= M){
        cout << 0 << endl;
        return 0;
    }

    // コマを重ねる意味はない
    // M個をN個のグループに分ける
    // ソートして差が開いている上位N-1個で区切ればよい
    sort(ALL(X));

    vector<pair<int, int>> dist;
    for(int i = 0; i < M-1; i++){
        dist.push_back(make_pair(X[i+1]-X[i], i+1));
    }

    sort(RALL(dist));

    // 1個は必ずどちらか端に置いた方が得
    // distのsecondが集合の先頭
    vector<int> l;
    l.push_back(0);
    for(int i = 0; i < N-1; i++){
        l.push_back(dist[i].second);
    }
    l.push_back(M);

    ll ans = 0;
    for(int i = 0; i < l.size()-1; i++){
        // printf("r = %d, l = %d\n", l[i], l[i+1]-1);
        ans += X[l[i+1]-1] - X[l[i]];
    }
    cout << ans << endl;
    return 0;
}