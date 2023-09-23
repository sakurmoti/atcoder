#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N,M,P;
    cin >> N >> M >> P;

    vector<ll> A(N+1,-1),B(M+1, 1e9);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= M; i++){
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    //B_sum[i] := B[i]までの総和
    //B_sum[l] - B_sum[r] := (r,l]の総和
    vector<ll> B_sum(M+1, 0);
    for(int i = 1; i <= M; i++){
        B_sum[i] += B_sum[i-1] + B[i];
    }

    ll b = 1;
    ll ans = 0;
    for(ll a = 1; a <= N; a++){
        //i < bに対しては全てP扱いできるので
        // printf("prev plus %d\n",b*P);
        ans += ((b-1)*P);

        while(A[a] + B[b] >= P && b <= M ){
            //これがPより大きければ、A[a] < A[a+1]から当然A[a+1] + B[b]もP以上
            //すなわちmin(s,P)からずっとPで固定できる
            // printf("as const A[%d] + B[%d] = %d\n",a,b,A[a]+B[b]);
            ans += P;
            b++;
        }

        //今、A[a] + B[b]はPより小さいので、足してあげる
        // for(ll i = b; i <= M; i++){
        //     // printf("a=%d, b=%d,  sum=%d\n",a,b,A[a]+B[b]);
        //     ans += A[a] + B[i];
        // }
        //これをO(1)で求めたい

        ans += (B_sum[M] - B_sum[b-1]); //Bの総和を累積和で高速に
        ans += (A[a] * (M-b+1)); //同じくAも
        
    }

    cout << ans << endl;
    return 0;
}