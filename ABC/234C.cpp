#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long K;
    cin >> K;

    stack<char> ans;

    //二進数に直すかのようにループ
    while(K != 0){
        int mod = K%2;
        mod *= 2; //0と2のどちらかになるように
        ans.push(mod + '0'); //スタックにcharとして挿入
        K /=2;
    }

    //スタックが空になるまで繰り返す
    while( ans.size() != 0 ){
        cout << ans.top(); //末尾を出力
        ans.pop(); //末尾を削除
    }

    cout << endl;

    return 0;
}