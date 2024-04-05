#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll a,b,C; cin >> a >> b >> C;

    constexpr int N = 60;

    // 先にxorの1を揃えてから0のところでpopcountを合わせるイメージ
    bitset<N> X(0),Y(0),Z(C);
    ll x = a, y = b;
    for(int i = 0; i < N; i++){
        if(Z.test(i)){
            if(x > y){
                x--;
                X.set(i);
            }else{
                y--;
                Y.set(i);
            }
        }
    }

    for(int i = 0; i < N; i++){
        if(!Z.test(i) && x > 0){
            X.set(i);
            Y.set(i);
            x--;
            y--;
        }
    }

    cerr << "countX : " << X.count() << endl;
    cerr << "countY : " << Y.count() << endl;
    cerr << "X ^ Y : " << (X xor Y).to_ullong() << endl;
    if(X.count() != a || Y.count() != b || (X xor Y).to_ullong() != C){
        cout << -1 << endl;
        return 0;
    }

    cout << X.to_ullong() << " " << Y.to_ullong() << endl;
    return 0;
}