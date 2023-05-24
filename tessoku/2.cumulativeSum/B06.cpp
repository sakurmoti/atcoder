#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    //累積和に当たりの数をいれる
    int a;
    vector<long long> cumSum(N+1,0);
    for(int i = 1; i <= N; i++){
        cin >> a;
        cumSum.at(i) = cumSum.at(i-1) + a;
    }

    int Q,L,R;
    cin >> Q;

    for(int i = 0; i < Q; i++){
        cin >> L >> R;
        int success = cumSum.at(R) - cumSum.at(L-1);
        int fail = (R-L+1) - success;

        if(success == fail){
            cout << "draw" << endl;
        
        }else if(success < fail){
            cout << "lose" << endl;
        
        }else if(success > fail){
            cout << "win" << endl;

        }
    }
    return 0;
}