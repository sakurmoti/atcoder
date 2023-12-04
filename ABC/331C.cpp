#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> A(N+1,0);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    auto B = A;

    sort(ALL(B));

    vector<ll> sum(N+10, 0);
    for(int i = 1; i <= N; i++){
        sum[i] = sum[i-1] + B[i];
    }

    for(int i = 1; i <= N; i++){
        int ok = N+1;
        int ng = 0;
        while(abs(ok-ng) > 1){
            int mid = (ok+ng)/2;

            if(A[i] < B[mid]){
                ok = mid;
            }else{
                ng = mid;
            }
            // cout << ok << " " << ng << endl;
        }

        // printf("ok=%d ",ok);
        // cout << sum[N] << " " <<  sum[ng] << endl;
        cout << sum[N] - sum[ng] << endl;
    }
    return 0;
}