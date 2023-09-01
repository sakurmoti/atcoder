#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    string S; cin >> S;

    //あるところを境に EEE?WWW と分けれればよい
    //リーダーを左から動かしていくと、変わるのは前リーダーだった人と、今リーダーになった人のみ
    
    //初めに1番目をリーダーとして全員西を向かせることを考える
    int cnt=0;
    for(int i = 1; i < N; i++){
        if(S[i] == 'E') cnt++;
    }

    //次にリーダーを一つずつずらす
    int ans = cnt;
    for(int i = 1; i < N; i++){
        if(S[i-1] == 'W') cnt++; //前のリーダーが西を向いてるなら東へ
        if(S[i] == 'E') cnt--; //今のリーダーが東を向いていたなら西に向かせなくてもよくなる
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}