#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    string S;
    cin >> S;

    //dp[i][j]をi文字目からj文字目まで見たとき嬉しい列かどうか
    //dp[i][j]からdp[i+2][j]、dp[i+1][j+1]、dp[i][j+2]に
    int N = S.size();
    vector<vector<bool>> dp(N, vector<bool>(N, false));
    vector<int> num(10,0);
    for(int j = 1; j <= N; j++){
        int i = 1;

        int x = S[j-1] - '0';
        num[x]++;

        //数字の個数がすべて偶数か
        bool flag = true;
        for(int k = 0; k < 9; k++){
            if(num[k]%2 == 0){
                cout << "y";
            }else{
                cout << "No";
                flag = false;
                break;
            }
        }
        cout << endl;
    
        if(flag){
            cout << i << "," << j << endl;
        }
    }
    return 0;
}