#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S; cin >> S;
    int N = S.size();

    int ans = 0;
    for(int st = 0; st < N; st++){
        for(int ed = st; ed < N; ed++){
            int len = ed - st + 1;
            bool rev = true;

            for(int i = st, j = ed; i < j ; i++, j--){
                if(S[i] != S[j]){
                    rev = false;
                    break;
                }
            }

            if(rev) ans = max(ans, len);
        }
    }

    cout << ans << endl;
    return 0;
}