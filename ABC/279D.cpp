#include <bits/stdc++.h>
using namespace std;

int main(){
    long long A,B;
    cin >> A >> B;

    /*愚直
    int g = 2;
    float time = A;
    while(time > (A/sqrt(g)) + (g-1)*B){
        time = (A/sqrt(g)) + (g-1)*B;
        g++;
        //cout << time << endl;
    }
    cout << g << endl;
    cout << time << endl;*/

    //A/sqrt(g) + (g-1)*Bを微分してB - A/(2g*sqrt(g)) = 0
    //=0は難しいので負から正に変わるときと見る
    //つまり2g*sqrt(g) <= A/B から2(g+1)*sqrt(g+1) > A/Bに変わるようなg
    double AB = A/B;
    long long g = 1;
    
    if(2 < AB){
        //二分探索
        long long ok = 1;
        long long ng = 1e18;
        while(abs(ok - ng) > 1){
            //printf("ok=%lld, ng=%lld\n", ok,ng);
            g = (ok+ng)/2;

            if(2*g*sqrt(g) <= AB){
                ok = g;

            }else{
                ng = g;

            }
        }
    }

    //cout << g << endl;
    double ans = A/sqrt(g) + (g-1)*B;
    printf("%10lf\n", ans);

    return 0;
}