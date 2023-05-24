#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    int Q,X;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> X;

        int ok = N;
        int ng = -1;
        int mid = (ok+ng)/2;
        while(abs(ok-ng) >= 2){
            if(A.at(mid) < X){
                ng = mid;
            
            }else{
                ok = mid;
            
            }

            mid = (ok+ng)/2;
        }

        cout << ng+1 << endl;
    }
    return 0;
}