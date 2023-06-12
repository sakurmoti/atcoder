#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> s(M);
    vector<char> c(M);
    map<int, int> dict;
    for(int i = 0; i < M; i++){
        cin >> s[i] >> c[i];
        s[i]--;
    }

    int ans = 10000;
    for(int i = 0; i < 1000; i++){
        string S = to_string(i);
        
        if(S.size() != N) continue;
        bool flag = true;
        for(int j = 0; j < M; j++){
            if(S[s[j]] != c[j]){
                flag = false;
                break;
            }
        }

        if(flag) ans = min(ans, i);
    }

    if(ans >= 1000){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}