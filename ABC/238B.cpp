#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    vector<int> cut_rad(N+1);
    for(int i = 0; i < N; i++){
        //cout << "i = "<< i << endl;
        for(int j = 0; j <= i; j++){
            //回転していって、360度を越えたら0に戻す
            cut_rad.at(j) += A.at(i);
            cut_rad.at(j) %= 360;
            //cout << j << " : " << cut_rad.at(j) << endl;
        }
    }

    //12時から順に切れ目を見ていく
    sort(cut_rad.begin(), cut_rad.end());
    //最後に360度のところに切れ目を入れる
    cut_rad.push_back(360);

    //初期値は一つ目の切れ目と12時の差分、つまりcut_rad.at(0)-0
    int max = cut_rad.at(0);
    for(int i = 0; i <= N; i++){
        int dr = cut_rad.at(i+1) - cut_rad.at(i);
        if(max < dr) max = dr;
    }
    cout << max << endl;
    return 0;
}