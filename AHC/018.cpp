#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

/*
コンテスト中のメモ
2/19 :　パワーの決め方について
    定数Cが小さければ試行回数を増やしてもよい -> Pを小さめにとる
    Cが大きければあまり試行したくないのでPを大きめにとる -> P= 5000/2 = 2500 から始めて破壊できなかったらP= 2500/2 = 1250 のようにする？
    Pの最大値は5000なので媒介変数tを用いてPmax/tを基準にパワーを決めればよい？
    小さめに取りたければtを大きく、大きめに取りたければtを小さくする

2/19 :　ルートの決め方
    とりあえず水路と家を直線でつないだ最短経路かな
    座標の引き算で計算して配列にどのマスを壊せばいいか入れておく感じ？
    そのマスが壊れているかは記憶したほうがよさそう
*/

struct point{
    int row; //上からi行目
    int column; //左からj列目
};

int N,W,K,C;
vector<point> water,house;
vector<vector<int>> isBroken; //-1で破壊完了。0以上であれば何回壊そうと試したか

void Input(){
    cin >> N >> W >> K >> C;
    water.resize(W);
    house.resize(K);
    isBroken.resize(N, vector<int>(N,0));
    for(int i = 0; i < W; i++) cin >> water[i].row >> water[i].column;
    for(int i = 0; i < K; i++) cin >> house[i].row >> house[i].column;
}

int Output(int x, int y, int P){
    int ret;
    cout << y << " " << x << " " << P << endl;

    cin >> ret;
    return ret;
}

int main(){
    Input();
    
    //ここに最短経路を計算してOutputしていく
    return 0;
}