#include <bits/stdc++.h>
using namespace std;

int main(){
    int D,N;
    cin >> D >> N;

    int L,R;
    vector<int> imos(D+10, 0);
    for(int i = 0; i < N; i++){
        cin >> L >> R;
        //L日目に一人増える。R+1日目に一人減る
        imos.at(L)++;
        imos.at(R+1)--;

    }

    //for(auto v : imos) cout << v << endl;
    
    //累積和を取ればimos法になる
    for(int i = 1; i <= D; i++){
        imos.at(i) += imos.at(i-1);

        cout << imos.at(i) << endl;
    }
    return 0;
}