#include <bits/stdc++.h>
using namespace std;

int main(){
    int R,C;
    cin >> R >> C;

    bool flag = false;
    //枠の横についてみていく
    for(int top = 1, buttom = 15; top < buttom; top+=2, buttom-=2){
        if(R == top || R == buttom){
            if(top <= C && C <= buttom){
                flag = true;
            }
        }
    }

    //枠の縦について
    for(int top = 1, buttom = 15; top < buttom; top+=2, buttom-=2){
        if(C == top || C == buttom){
            if(top <= R && R <= buttom){
                flag = true;
            }
        }
    }

    if(flag) cout << "black" << endl;
    else cout << "white" << endl;

    return 0;
}