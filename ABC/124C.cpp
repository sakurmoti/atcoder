#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;

    int N = S.size();
    string s1,s2;
    for(int i = 0; i < N; i++){
        s1.push_back(i%2 + '0');
        s2.push_back((i+1)%2 + '0');
    }
    // cout << s1 << " " << s2 << endl;
    int cnt1=0, cnt2=0;
    for(int i = 0; i < N; i++){
        if(S[i] != s1[i]){
            cnt1++;
        }

        if(S[i] != s2[i]){
            cnt2++;
        }
    }
    // cout << cnt1 << " " << cnt2 << endl;

    cout << min(cnt1, cnt2) << endl;
    return 0;
}