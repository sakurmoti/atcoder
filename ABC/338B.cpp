#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    vector<int> cnt(100, 0);
    for(int i = 0; i < S.size(); i++){
        cnt[S[i] - 'a']++;
    }

    char ans = 'a';
    int M = -1;
    for(int i = 0; i <= 26; i++){
        if(M < cnt[i]){
            ans = (char)('a' + i);
            M = cnt[i];
        }
    }

    cout << ans << endl;
    return 0;
}