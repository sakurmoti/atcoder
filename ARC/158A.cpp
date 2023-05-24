#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void solve(){
    vector<int> x(3);
    cin >> x[0] >> x[1] >> x[2];

    //条件1.偶奇は同時に変わるので最初で一致の必要あり
    if(!(x[0]%2 == x[1]%2 && x[0]%2 == x[2]%2)){
        cout << -1 << endl;
        return;
    }

    //最小に+7,真ん中に+5,最大に+3で差がそれぞれ4と2ずつ縮まる
    //以下x <= y <= zとする
    sort(x.begin(), x.end());

    int xy = x[1]-x[0];
    int yz = x[2]-x[1];
    int zx = x[2]-x[0];

    //常に上の操作が最適
    //上の操作で最初にどれかが等しくなるタイミングを探す
    int xnt = xy/2;
    int ynt = yz/2;
    int znt = zx/4;
    int mnt = min({xnt,ynt,znt});
    
    //printf("xnt=%d, ynt=%d, znt=%d\n", xnt,ynt,znt);

    //二つが等しくなったら2回の操作で6ずつ縮めることができる -> 差が6の倍数である必要
    int ans = 0;
    if(mnt == xnt){
        //x,yが等しい状態
        x[0] += (xnt*7);
        x[2] += (xnt*3);

        if((abs(x[2]-x[0]))%6 == 0){
            ans += xnt;
            ans += 2*((x[2]-x[0])/6);
        
        }else{
            cout << -1 << endl;
            return;
        }

    }else if(mnt == ynt){
        //y,zが等しい状態
        x[0] += (ynt*7);
        x[2] += (ynt*3);

        if((abs(x[2]-x[0]))%6 == 0){
            ans += ynt;
            ans += 2*((x[2]-x[0])/6);
        
        }else{
            cout << -1 << endl;
            return;
        }

    }else if(mnt == znt){
        //x,zが等しい状態
        x[0] += (znt*7);
        x[1] += (znt*5);

        if((abs(x[0]-x[1]))%6 == 0){
            ans += znt;
            ans += 2*((x[2]-x[0])/6);
        
        }else{
            cout << -1 << endl;
            return;
        }

    }

    cout << ans << endl;
}

int main(){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        solve();
    }
    return 0;
}