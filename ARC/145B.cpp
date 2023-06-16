#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll N,A,B;
    cin >> N >> A >> B;

    /*
    n < Aのとき、明らかにAliceの負け
    A <= Bのとき、石を取れるだけ取れれば勝つ
    A > Bのとき、石がA個以上でBobにターンが回ると前述の議論から必ず負ける -> 石を取れるだけ取ってB未満になれば勝つ

    故にAliceが勝つのは n >= A かつ ((A <= B)または(n mod A < B))
    A <= Bのときn mod A < Bは常に成り立つので n >= A かつ n mod A < Bである
    */

    if(N < A){
        cout << 0 << endl;
    
    }else{
        // f(x) := n=[1,x]においてnをAで割ったあまりがB未満である整数の個数
        // f(N) - f(A-1)を求めればよい

        // 周期の個数 + 最後の個数
        auto f = [&](ll X){return (X/A)*min(A,B) + min(X%A, B-1); };
        cout << f(N) - f(A-1) << endl;

    }
    return 0;
}