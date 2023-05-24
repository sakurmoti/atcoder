#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;

    //an = (n-1)d + a0
    //Sn = (a0 + an) * (n/2)
    //2*N = (a0+an) * n
    //素因数分解してうまく行きそう

    //個数nは公差1のときan-a0+1で表される
    //2N = x*yに分かれるとすると
    // an + a0 = x
    // an - a0 + 1 = y
    //これを解くと
    // a0 = (x-y+1)/2
    // an = (x+y-1)/2
    //数列aは整数よりx-y+1, x+y-1は偶数でなければならない。つまりx,yは偶奇が異なる必要がある
    //x,yどちらか一方に素因数2を持たせて、他の約数の個数を配ればよい
    
    while(N%2==0) N/=2;
    int cnt = 0;
    for(long long i = 1; i*i <= N; i++){
        if(N%i == 0){
            //iとN/iの2つの約数をカウント
            cnt += 2;
        }
        //iとN/iが同じ = 重複して数えてしまうので1引く
        if(i*i == N) cnt--;
    }
    cout << cnt*2 << endl;
    return 0;
}