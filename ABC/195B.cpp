#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,W;
    cin >> A >> B >> W;

    //グラムに直す
    W *= 1000;

    int quotient, modulo; //商とあまり
    /*最小値探索
    なるべくBで割り切れたら少なくなる
    余った分はA kg分の果物を追加してBから増やしすぎた分を減算する
    減算しきれないならちょうどWにできないということ*/
    quotient = W/B;
    modulo = W%B;
    if(modulo != 0 && A-modulo > (B-A)*quotient){
        //減算しきれない
        cout << "UNSATISFIABLE" << endl;
        return 0;

    }else if(modulo == 0){
        cout << quotient << " ";
    }else{
        cout << quotient+1 << " ";
    }


    /*最大値探索
    なるべくAで割り切れたら多くなる
    余った分はBを超えない範囲でAに加算する
    もしそれで分割しきれないようであればそもそもちょうどWにできないということ*/
    quotient = W/A;
    modulo = W%A;
    
    if(modulo > (B-A)*quotient){
        //あまりを分割しきれない
        cout << "UNSATISFIABLE" << endl;
        return 0;

    }else{
        //分割しきれる
        cout << quotient << endl;
    }

    return 0;
}