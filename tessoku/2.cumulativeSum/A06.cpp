#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;

    vector<int> A(N+1,0);
    vector<long long> cumSum(N+1,0);
    for(int i = 1; i <= N; i++){
        cin >> A.at(i);
        cumSum.at(i) = cumSum.at(i-1) + A.at(i);
        //cout << cumSum.at(i) << endl;
    }

    int L,R;
    for(int i = 0; i < Q; i++){
        cin >> L >> R;


        cout << cumSum.at(R) - cumSum.at(L-1) << endl;
    }
    return 0;
}