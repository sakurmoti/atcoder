#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;

    /*
    終了する確率p、一回にかかる時間をtとすると
    求める期待値yは、y = t + (1-p)*yなので
    py = t から y = t/pを得る
    p = (1/2)^Mであることに注意して、1/p = 2^M
    */
    
    ll t = 1900 * M + 100*(N-M);
    ll p = pow(2,M);
    cout << t*p << endl;
    return 0;
}