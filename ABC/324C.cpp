#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    string T2; cin >> T2;

    vector<int> ans;
    for(int i = 0; i < N; i++){
        string S; cin >> S;

        int suffix=0, prefix=0;
        for(int j=0,k=0; (j<S.size()) && (k<T2.size()); j++,k++){
            if(S[j] == T2[k]) prefix++;
            else break;
        }

        for(int j=S.size()-1, k=T2.size()-1; (j>=0)&&(k>=0); j--,k--){
            if(S[j] == T2[k]) suffix++;
            else break;
        }

        bool flag = false;

        // SはT'と等しい : pre = suf = |S| = |T'|
        if( (S.size() == T2.size()) && (prefix == S.size()) ) flag = true;
    
        // Sに1文字挿入したのがT' : pre+suf >= |S| = |T'|-1
        if( (prefix+suffix >= S.size()) && (S.size() == T2.size()-1) ) flag = true;

        // Sを1文字消したのがT' : pre+suf >= |S|-1 = |T'|
        if( (prefix+suffix) >= S.size()-1 && (S.size()-1 == T2.size()) ) flag = true;

        // Sから1文字置き換えたのがT' : pre + suf = |S|-1 = |T'|-1
        if ( (prefix+suffix == S.size()-1) && (S.size()-1 == T2.size()-1) ) flag = true;

        if(flag) ans.push_back(i+1);
    }

    cout << ans.size() << endl;
    for(auto &_v : ans) cout << _v << ' ';
    return 0;
}