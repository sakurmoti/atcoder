#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    string T; cin >> T;
    int lenT = T.size();

    vector<int> ans;
    for(int i = 0; i < N; i++){
        string S; cin >> S;
        int lenS = S.size();

        int pre=0,suf=0;
        for(int j = 0; j < min(lenS, lenT); j++){
            if(S[j] != T[j]) break;
            pre++;
        }
        for(int j = 1; j <= min(lenS, lenT); j++){
            if(S[lenS-j] != T[lenT-j]) break;
            suf++;
        }

        printf("S = %s, pre = %d, suf = %d\n", S.c_str(), pre, suf);

        if(lenS == lenT && lenT == pre && pre == suf){
            // TはSと等しい
            ans.push_back(i+1);
        
        }else if(lenS-1 == lenT && lenT <= (pre + suf)){
            // TはSの1文字を削除したものに等しい
            ans.push_back(i+1);
        
        }else if(lenS+1 == lenT && lenS <= (pre + suf)){
            // TはSに1文字挿入したものに等しい
            ans.push_back(i+1);

        }else if(lenS == lenT && lenS == (pre + suf + 1)){
            // TはSを1文字変更したものに等しい
            ans.push_back(i+1);

        }
    
    }

    cout << ans.size() << endl;
    for(auto &_v : ans) cout << _v << " "; cout << endl;
    return 0;
}