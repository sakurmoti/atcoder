#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;

    //ドからシ　: WBWBWWBWBWBW
    //ソからファ: WBWBWWBWBWWB　なので、WBWBWWBWBWBまで確定させればドとわかる
    //それよりミ: WWBWBWBWWB がわかりやすそうなのでミを探す
    //類似のシは: WWBWBWW なので WWBWBWBを探せば良い
    string mi = "WWBWBWB";
    int mi_idx = 0;

    string music[] = {"Do", "Do", "Re", "Re", "Mi", "Fa", "Fa", "So", "So", "La", "La", "Si"};
    
    int idx = S.find(mi);
    cout << music[(4-idx + 12)%12] << endl; //ミは4から、+12してmodの正負を気を付ける
    return 0;
}