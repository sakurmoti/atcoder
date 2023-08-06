#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,D;
    cin >> N >> D;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    int ans=0, cnt=0;
    for(int j = 0; j < D; j++){
        bool flag = true;
        for(int i = 0; i < N; i++){
            if(S[i][j] == 'x') flag = false;
        }

        if(flag) cnt++;
        else cnt=0;

        ans = max(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}