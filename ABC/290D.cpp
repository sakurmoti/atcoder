#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//最大公約数 ユークリッドの互除法 O(log(X+Y))
long long GCD(long long X, long long Y){
    if(Y == 0) return X;
    return GCD(Y, X%Y);
}

//最小公倍数 X*Y = GCD(X,Y)*LCM(X,Y)を利用 O(log(X+Y))
long long LCM(long long X, long long Y){
    long long gcd = GCD(X,Y);
    return (X/gcd)*Y;
}

void solve(){
    long long N,D,K;
    cin >> N >> D >> K;
    K--;

    //結局進むのは　D % N だけなのでD %= Nとしても同値
    D %= N;

    //すると次同じマスを通るのはNとDの最小公倍数のとき
    long long nex = LCM(N,D);
    //cout << nex << endl;
    //この nex%N のマスに止まると+1される
    //+1されると隣は開いている..?

    //nex/D回繰り返せる
    long long unit = nex/D;
    
    //繰り返す度に+1されるので
    long long rotate = K/unit;
    long long per = ((K%unit)*D)%N;
    long long ans = rotate + per;
    
    //printf("nex = %d, unit = %d, rotate = %d, per = %d ans = ", nex%N, unit, rotate, per);
    cout << ans << endl;
}

int main(){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        solve();
    }
    return 0;
}