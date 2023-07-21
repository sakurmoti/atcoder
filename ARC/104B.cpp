#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    string S; cin >> S;

    int ans = 0;
    for(int i = 0; i < N; i++){
        //開始位置
        map<char, int> cnt;
        for(int j = 0; j < N-i; j++){
            //から何文字か
            char c = S[i+j];
            cnt[c]++;

            if(cnt['A'] == cnt['T'] && cnt['C'] == cnt['G']) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}