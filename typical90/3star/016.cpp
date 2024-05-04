#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> coin(3);
    cin >> coin[0] >> coin[1] >> coin[2];
    sort(coin.begin(), coin.end());

    int min=10000;
    for(int A = 0; A < 10000; A++){
        for(int B = 0; A+B < 10000; B++){
            int maxC = 9999-A-B;
            //残り残金がCで割り切れるか
            int mod = N - A*coin[0] - B*coin[1];
            if(mod%coin[2]==0 && 0<=mod/coin[2] && mod/coin[2]<=maxC){
                int C = mod/coin[2];
                if(min > A+B+C){
                    min = A+B+C;
                }
            }
        }
    }

    cout << min << endl;
    return 0;
}