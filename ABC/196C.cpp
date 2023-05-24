#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;

    /*11×1桁(1~9)で2桁の反転を、101×2桁(10~99)で4桁の反転を、1001×3桁(100~999)で6桁の反転を作れる*/

    long long ans=0;

    //99,9999,999999などの区切りが着くところまでをまとめてカウント
    long long c=1;
    while(true){
        if(N/((10*c)*(10*c)) != 0){
            ans += 9*c;
        
        }else{
            break;
        }

        c*=10;
    }

    //区切りのつかないものはループでカウントする
    long long unit = 1*(c*10) + 1; //11,101,1001..をつくる
    for(int i = c; i < c*10; i++){
        if(N/(i*unit) != 0){
            ans++;

        }else{
            break;
        
        }
    }

    cout << ans << endl;
    return 0;
}