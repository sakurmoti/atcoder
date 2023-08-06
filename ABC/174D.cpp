#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    string S; cin >> S;

    //あるところを境に赤の塊を左に、白の塊を右に並べればよい
    int W=0, R=0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'W') W++;
        else R++;
    }

    int rightW = 0;
    int leftR = R;
    int ans = max(rightW, leftR); //一番左で区切る場合

    //0 <= j <= iの石を赤として区切る => SiとSi+1の間で区切る
    for(int i = 0; i < N; i++){
        if(S[i] == 'W'){
            rightW++;
        }else{
            leftR--;
        }
        ans = min(ans, max(rightW, leftR));
    }
    
    cout << ans << endl;
    return 0;
}