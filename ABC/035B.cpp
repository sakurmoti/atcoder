#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S; cin >> S;
    int T; cin >> T;

    //求めるのはマンハッタン距離なので、縦横分割して考える
    int N = S.size();
    int x=0, y=0, q=0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'R') x++;
        if(S[i] == 'L') x--;

        if(S[i] == 'U') y++;
        if(S[i] == 'D') y--;
        
        if(S[i] == '?') q++;
    }

    if(T==1){
        //最大値を求める
        //xまたはyに伸ばしまくればよい
        cout << abs(x) + abs(y) + q << endl;

    }else{
        //最小値を求める
        //'?'を使ってなるべく原点に近づけた後、その場を往復させる
        if(q >= abs(x)){
            q -= abs(x);
            x = 0;
        }else{
            x = abs(x) - q;
            q = 0;
        }

        if(q >= abs(y)){
            q -= abs(y);
            y = 0;
        }else{
            y = abs(y) - q;
            q = 0;
        }

        cout << abs(x) + abs(y) + q%2 << endl;

    }
    return 0;
}