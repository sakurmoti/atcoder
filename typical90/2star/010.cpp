#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    //0にクラス、1に番号を入れる。2,3にi番目までの総和を入れるため、一度別の配列に入れる
    vector<tuple<int, int, int, int>> CP(N+1);
    vector<int> buf(N);
    for(int i = 1; i <= N; i++){
        get<1>(CP.at(i)) = i;
        cin >> get<0>(CP.at(i)) >> buf.at(i-1);
    }

    get<2>(CP.at(0)) = get<3>(CP.at(0)) = 0;
    //2にはクラス1の、3にはクラス3の点数の総和を入れることで計算量を減らす
    //クラスが違う場合はそれ以前のものを保持するようにする
    for(int i = 1; i <= N; i++){
        if(get<0>(CP.at(i)) == 1){
            get<2>(CP.at(i)) = buf.at(i-1) + get<2>(CP.at(i-1));
            get<3>(CP.at(i)) = get<3>(CP.at(i-1));
        }else{
            get<3>(CP.at(i)) += buf.at(i-1) + get<3>(CP.at(i-1));
            get<2>(CP.at(i)) = get<2>(CP.at(i-1));
        }
    }

    /*for(int i = 0; i <= N; i++){
        cout << i << " Score : " << get<3>(CP.at(i)) << endl;
    }*/

    int Q,R,L;
    cin >> Q;

    for(int i = 0; i < Q; i++){
        cin >> L >> R;

        //クラス1について
        cout << get<2>(CP.at(R))-get<2>(CP.at(L-1)) << " ";

        //クラス2について
        cout << get<3>(CP.at(R))-get<3>(CP.at(L-1)) << endl;

    }
    return 0;
}