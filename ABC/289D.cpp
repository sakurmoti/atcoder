#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int M;
    cin >> M;
    vector<bool> mochi(1e6, false);
    for(int i = 0; i < M; i++){
        int B;
        cin >> B;

        mochi.at(B) = true;
    }

    int X;
    cin >> X;

    vector<bool> dp(1e6, false);
    dp[0] = true;

    for(int i = 0; i <= X; i++){
        if(dp[i]){
            if(!mochi[i]){
                for(auto v : A) dp[i+v] = true;
            }
        
        }
    }

    bool flag = dp[X];
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}