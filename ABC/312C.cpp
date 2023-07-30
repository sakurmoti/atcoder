#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    vector<ll> A(N, -1), B(M, -1);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < M; i++){
        cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll ok = 1e10;
    ll ng = 0;
    while(abs(ok-ng) >= 2){
        ll mid = (ok+ng)/2;
        int cntA = distance(A.begin(), upper_bound(A.begin(), A.end(), mid) ); //売ってもよい売り手の人数
        int hogeB = distance(B.begin(), lower_bound(B.begin(), B.end(), mid) ); //買いたくない人の人数
        int cntB = M-hogeB;

        // printf("mid=%d cntA=%d, cntB=%d\n",mid,cntA,cntB);

        if(cntA >= cntB){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}