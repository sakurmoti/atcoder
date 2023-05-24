#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,M,D;
    cin >> N >> M >> D;

    vector<long long> A(N), B(M);
    for(auto &v : A) cin >> v;
    for(auto &v : B) cin >> v;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int am = N-1;
    int bm = M-1;
    while(true){
        if(am<0 || bm<0){
            cout << -1 << endl;
            break;
        }

        if(abs(A[am]-B[bm]) <= D){
            cout << A[am] + B[bm] << endl;
            break;
        
        }else{
            if(A[am] < B[bm]){
                bm--;

            }else{
                am--;
            
            }
        }

    }
    return 0;
}