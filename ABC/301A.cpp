#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    string S;
    cin >> N >> S;

    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'T') cnt1++;
        else cnt2++;
    }

    if(cnt1 > cnt2) cout << 'T' << endl;
    else if(cnt1 < cnt2) cout << 'A' << endl;
    else if(S[N-1] == 'T') cout << 'A' << endl;
    else cout << 'T' << endl;
    return 0;
}