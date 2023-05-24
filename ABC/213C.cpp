#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W,N;
    cin >> H >> W >> N;
    
    vector<int> x(N),y(N);
    for(int i = 0; i < N; i++){
        cin >> y.at(i) >> x.at(i);
    }

    //xについて座標圧縮
    auto X = x;
    sort(X.begin(), X.end());
    

    X.erase(unique(X.begin(), X.end()), X.end());
    //これで重複を除けた

    //あとはXの中の何番目にxの値が出るかを二分探索で調べる
    for(int i = 0; i < N; i++){
        //lower_bound内は配列Xのうち、x[i]以上になるような配列Xのイテレータを返す
        //これからX.beginのイテレータを引くことで何番目か求められる
        x.at(i) = lower_bound(X.begin(), X.end(), x.at(i)) - X.begin() +1;
    }


    //yについても同様
    vector<int> Y = y;
    sort(Y.begin(), Y.end());
    
    Y.erase(unique(Y.begin(),Y.end()), Y.end());

    for(int i = 0; i < N; i++){
        y.at(i) = lower_bound(Y.begin(), Y.end(), y.at(i)) - Y.begin() +1;
    }

    //出力
    for(int i = 0; i < N; i++){
        cout << y.at(i) << " " << x.at(i) << endl;
    }

    return 0;
}