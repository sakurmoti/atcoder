#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int H,W;
    cin >> H >> W;

    int x;
    for(int i = 0; i < H; i++){
        string ans;

        for(int j = 0; j < W; j++){
            cin >> x;
            
            if(x==0) ans += '.';
            else ans += ('A' + x - 1);
        }

        cout << ans << endl;
    }



    return 0;
}