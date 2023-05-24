#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> A(K);
    for(int i = 0; i < K; i++) cin >> A.at(i);
    
    //dp[i]はtrueなら石がi個あるとき先手必勝、falseなら後手必勝
    vector<bool> dp(N+1, false);
    dp[0] = false;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j < K; j++){
            if(dp.at(i) == true) break;

            if(i - A.at(j) >= 0 && dp.at(i-A.at(j)) == false){
                dp.at(i) = true;
            
            }else{
                dp.at(i) = false;

            }
        }
    }

    if(dp.at(N)) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}