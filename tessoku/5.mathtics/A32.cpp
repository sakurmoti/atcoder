#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,A,B;
    cin >> N >> A >> B;

    //N個の石があるときの勝者を表す配列。trueなら先手必勝、falseなら後手必勝
    vector<bool> winner(N+1);
    for(int i = 0; i < A; i++){
        winner[i] = false;
    }

    for(int i = A; i <= N; i++){
        if(winner[i-A] == true){
            //先手必勝の状態で相手に渡すので負け
            winner[i] = false;
        
        }else{
            //後手必勝の状態で相手に渡すので勝ち
            winner[i] = true;
        }

        //A個取るときに負ける場合でも、B個取って勝てる場合
        if(winner[i] == false && i-B >= 0 && winner[i-B] == false){
            winner[i] = true;
        }
    }

    if(winner[N]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}