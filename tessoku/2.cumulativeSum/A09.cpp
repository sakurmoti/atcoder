#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W,N;
    cin >> H >> W >> N;

    //二次元方向のimos法
    vector<vector<int>> snow(H+10, vector<int>(W+10, 0));
    int a,b,c,d;
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c >> d;

        //(a,b)では雪が1つ多いことを表す
        snow.at(a).at(b)++;

        //縦の差分を表すため(c+1,b)で雪が1つ少ないことを表す
        snow.at(c+1).at(b)--;

        //横の差分を表す
        snow.at(a).at(d+1)--;

        //横の累積和を取ったとき(c+1,d+1)でマイナスにならないようにストップをかけてあげる
        snow.at(c+1).at(d+1)++;
    }

    /*test
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cout << snow.at(i).at(j) << ((j != W) ? " " : "\n");
        }
    }*/

    //差分の累積和を取る
    //まずは横から
    for(int i = 0; i <= H; i++){
        for(int j = 0; j <= W; j++){
            snow.at(i).at(j+1) += snow.at(i).at(j);
        }
    }

    //次に縦に
    for(int j = 0; j <= W; j++){
        for(int i = 0; i <= H; i++){
            snow.at(i+1).at(j) += snow.at(i).at(j);
        }
    }

    //ans
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cout << snow.at(i).at(j) << ((j != W) ? " " : "\n");
        }
    }

    return 0;
}