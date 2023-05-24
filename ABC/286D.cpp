#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,X;
    cin >> N >> X;

    vector<long long> A(N), B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }

    //dp[i]は値段iを達成できるか
    //値段0は何も払わなければok
    vector<bool> dp(1e5, false);
    dp[0] = true;

    for(int j = 0; j < N; j++){
        vector<int> temp;

        for(int i = 0; i <= X; i++){
            if(dp[i] == true){

                for(int k = 0; k <= B.at(j); k++){
                    temp.push_back(i + k*A.at(j));

                }
            }
        }

        //ここで更新すれば枚数kを重複して数えなくて済む
        for(int k = 0; k < temp.size(); k++){
            if(X < temp.at(k)) continue;
            dp.at(temp.at(k)) = true;
        }
    }

    if(dp.at(X)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}