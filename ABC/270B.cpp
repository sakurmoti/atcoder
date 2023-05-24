#include <bits/stdc++.h>
using namespace std;

int main(){
    int goal, wall, hammer;
    cin >> goal >> wall >> hammer;

    int ans=0;

    /*壁を超える必要がないときは
    同符号かつゴールのほうが絶対距離が近い、または異符号のとき*/
    if( ((wall*goal>0) && (abs(goal)<abs(wall))) || (wall*goal<0) ){
        //ハンマーが不要
        ans = abs(goal);

    }else{
        //ハンマーが必要

        //ハンマーを取れるかどうか
        if( ((hammer*wall>0) && (abs(hammer)<abs(wall))) || (hammer*wall<0) ){
            ans = abs(hammer) + abs(goal - hammer);

        }else{
            ans = -1;
        }
    
    }

    cout << ans << endl;
    return 0;
}