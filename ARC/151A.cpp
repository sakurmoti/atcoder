#include <bits/stdc++.h>
using namespace std;

//写経
int main(){
    int N;
    string S,T;
    cin >> N >> S >> T;

    string ans(N, '0');
    int cS = count(S.begin(), S.end(), '1');
    int cT = count(T.begin(), T.end(), '1');

    for(int i = N-1; i >= 0; i--){
        if(cS > cT && S[i] == '1' && T[i] == '0'){
            ans[i] = '1';
            cS--;
            cT++;
        
        }else if(cS < cT && S[i] == '0' && T[i] == '1'){
            ans[i] = '1';
            cS++;
            cT--;
        }

        if(cS == cT) break;
    }

    if(cS == cT) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}