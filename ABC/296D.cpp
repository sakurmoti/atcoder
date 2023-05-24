#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    long long N,M;
    cin >> N >> M;

    //以下、a<=bとする
    //このとき、1<=a<=ceil(sqrt(M)) (ceil(sqrt(M))<aとすると、M < ab)
    //また、bは(1 <= a <= b <= N かつ M <= abからa <= (M/a) <= b <= Nが言える
    //このときb=ceil(M/a)なら条件を少なくともM <= abを満たす。
    //反対にこれ以上のbを探す必要はない。故にb = ceil(M/a)にするのが最適
    
    long long ans = 1e18;
    for(long long a = 1; a <= ceil(sqrt(M)); a++){
        long long b = (M+a-1)/a; //ceil(M/a)

        if(b <= N){
            ans = min(ans,a*b);
        }
        printf("%d %d\n",a,b);

        if(a>b) break;
    }
    
    if(ans==1e18) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}