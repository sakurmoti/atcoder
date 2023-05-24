//A16を配る遷移で解く

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N+1), B(N+1);
    for(int i = 2; i <= N; i++) cin >> A[i];
    for(int i = 3; i <= N; i++) cin >> B[i];
    
    vector<int> dp(N+1,1e9);
    dp.at(1) = 0;
    for(int i = 1; i <= N; i++){
        if(i+1 <= N){
            dp.at(i+1) = min(dp.at(i+1), dp.at(i)+A.at(i+1));
            
        }

        if(i+2 <= N){
            dp.at(i+2) = min(dp.at(i+2), dp.at(i)+B.at(i+2));
        }
    }

    cout << dp.at(N) << endl;
    return 0;
}