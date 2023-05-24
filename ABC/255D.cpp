#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    long long N,Q;
    cin >> N >> Q;
    
    vector<long long> A(N+1, 0);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    //対称性からソートしても同じ
    sort(A.begin(), A.end());

    //区間のAの総和をO(1)で出せるように累積和
    //S[i] := [0,i)の総和
    //もし[left,right)区間を求めたかったらS[right]-S[left]でいい
    vector<long long> S(N+10,0);
    for(int i = 1; i <= N; i++){
        S[i+1] = S[i] + A[i];
    }

    for(int q = 0; q < Q; q++){
        long long X; cin >> X;

        /*A[0] <= A[1] <= ... <= A[k] <= X <= A[k+1] <= ... <= A[N] なるkを探す
        この時の答えは
        (X-A[0]) + (X-A[1]) + .. + (X-A[k]) + (A[k+1]-X) + .. + (A[N]-X)
            = {(k+1)X - sum(A[0],A[k]) } + {sum(A[k+1],A[N]) - (N-k)X}
        になる。
        */

        int ok = 0;
        int ng = N+1;
        while(abs(ok-ng) > 1){
            int mid = (ok + ng)/2;
            if(mid < 0) break;

            if(A[mid] <= X) ok = mid;
            else ng = mid;

            //printf("ok=%d, ng=%d\n",ok,ng);
        }

        long long sum1 = 0, sum2 = 0;
        sum1 = ok*X - (S[ok+1]-S[0]);
        if(ng!=N+1) sum2 = (S[N+1] - S[ng]) - (N-ng+1)*X;
        cout << sum1 + sum2 << endl;
        
    }

    return 0;
}