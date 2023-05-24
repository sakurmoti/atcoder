#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> A(N);
    vector<long long> cumSum(N+1, 0);
    for(int i = 0; i < N; i++){
        cin >> A[i];

        cumSum.at(i+1) = cumSum.at(i) + A.at(i);
    }

    //尺取り
    int R = 0;
    long long ans = 0;
    for(int L = 0; L < N; L++){
        while(R < N){
            long long price = cumSum.at(R+1) - cumSum.at(L);

            if(price <= K){
                R++;
            
            }else{
                break;

            }
        }

        ans += R-L;

    }

    cout << ans << endl;
    return 0;
}