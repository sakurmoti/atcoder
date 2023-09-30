#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll A,B,N;
    cin >> A >> B >> N;

    auto f = [&](ll x){return ((A*x)/B) - A*(x/B);};

    // 三分探索と思ったが極値が一つを示せない
    // f(x+B) = f(x)を使う
    // 上により、0 <= x < Bの範囲を考えればよい
    // この範囲でfloor(x/B) = 0なのでf(x) = floor(Ax/B)
    // 0 < A,x,Bにおいて、これは明らかに単調増加なので、fの定義域の右端を計算すればよい
    
    cout << f(min(N, B-1)) << endl;

    return 0;
}