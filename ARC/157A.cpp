#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;

    //BとCはreverseしたら同じ
    //SでXYがB個、YXがC個あれば、rev(S)でXYがC個、YXがB個あればよい

    //XYでYスタートに変えられる。またXスタートに戻さないとXYの形が作れないのでYXをどこかで使わないといけない
    //つまりBとCの差が1以上だと必ずできない      条件1: abs(B-C) <= 1

    //また、BかCのどちらが大きいかによって最初が決まる
    //Bが大きいならXYを増やさないといけない　->　YスタートだとYXの方が多くなってしまうのでXスタートでないといけないということ
    //同じならどちらから始めてもよいが、終わりがスタートと同じ文字である必要がある
    
    //実はAとDの数はXYかYXがあれば自由にいじれるのでいくらでも良い？
    //逆にBとCが0なのにAとDが1以上だと絶対むり  <- 条件2

    bool ans = true;
    //条件1
    if(abs(B-C) <= 1){
        //条件2
        if(A >= 1 && B == 0 && C == 0 && D >= 1){
            ans = false;
        
        }

    }else{
        ans = false;
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}