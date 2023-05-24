#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    string S;
    cin >> S;

    //swapするというより、"atcoder"の先頭の文字から順に前に持ってくればいい
    int ans = 0;
    int N = 7;
    string AC = "atcoder";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char ac = AC[i];
            char s = S[j];

            if(ac == s){
                ans += abs(i-j);
                S.erase(S.begin()+j);
                S.insert(S.begin()+i, s);
                break;
            }
        }
        cout << S << endl;
    }
    cout << ans << endl;
    return 0;
}