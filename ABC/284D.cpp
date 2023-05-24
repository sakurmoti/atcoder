#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int test = 0; test < T; test++){
        long long N;
        cin >> N;

        long long x,y;
        for(long long i = 2; i*i*i <= N; i++){
            if(N%i == 0){
                x = i;
                y = N/x;
                break;
            }
        }

        if(y < x){
            long long temp = y;
            y = x;
            x = temp;
        }
        //N = x*y (x < y)にできた
        //printf("%lld = %lld * %lld\n", N,x,y);

        long long p,q;
        if(y % x == 0){
            //yがxで割れるならN = x*y = x*x*(y/x)ゆえにp = x
            p = x;
            q = y/x;
        
        }else{
            //yがxで割れない時、q=yが確定
            p = (long long)sqrt(y);
            q = x;

        }

        cout << p << " " << q << endl;
        
    }
    return 0;
}