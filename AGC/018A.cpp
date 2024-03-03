#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,K; cin >> N >> K;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    /*
     abs(a-b) < max(a,b)なのでK <= max(A)の必要あり
     g = GCD(A)とすると、A = {ga', gb', gc' ...}で表せる
     操作をしても |ga'-gb'| = g * |a'-b'| を得るので配列の最大公約数はgのまま
    */

    int g = accumulate(ALL(A), 0, [](int x, int y){return gcd(x,y);} );
    
    if(K%g == 0 && K <= *max_element(ALL(A))) cout << "POSSIBLE\n";
    else cout << "IMPOSSIBLE\n";


    return 0;
}