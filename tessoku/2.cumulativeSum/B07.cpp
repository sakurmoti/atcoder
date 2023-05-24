#include <bits/stdc++.h>
using namespace std;

int main(){
    int T,N;
    cin >> T >> N;

    int L,R;
    vector<int> imos(T+10,0);
    for(int i = 0; i < N; i++){
        cin >> L >> R;

        //時刻tの従業員の増分をimos[t]に入れる
        imos.at(L)++;
        imos.at(R)--;
    }

    for(int i = 0; i < T; i++){
        if(i == 0){
            cout << imos.at(0) << endl;

        }else{
            imos.at(i) += imos.at(i-1);
            cout << imos.at(i) << endl;

        }
    }
    return 0;
}