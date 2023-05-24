#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C,D,E,F,X;
    cin >> A >> B >> C >> D >> E >> F >> X;

    /*
    A秒間のジョギングとC秒間の休憩を1セットとしてみなすと
    (A*B) := 1セットで進む距離
    (X/(A+C)) := 何セット行えるか
    
    min(a,b) := 最小値を得る関数。a,bのうち小さい方の値を得る
    X%(A+C) := 最後の1セットできなかった時の残ってる時間
    min(X%(A+C), A) := 走ってる時間は最大でもA秒、A秒以下ならX%(A+C)秒の値を得る
    */
    int takahashi = (A*B)*(X/(A+C)) + min(X%(A+C), A)*B;
    int aoki = (D*E)*(X/(D+F)) + min(X%(D+F), D)*E;

    if(takahashi < aoki){
        cout << "Aoki" << endl;
    
    }else if(takahashi == aoki){
        cout << "Draw" << endl;

    }else{
        cout << "Takahashi" << endl;

    }
    return 0;
}