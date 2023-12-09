#include <bits/stdc++.h>
using namespace std;

const int N = 100; //グラフの頂点数(4<=N<=100)
int M; //出力するグラフ数
float eps; //エラー率

vector<vector<int>> Graph;
vector<int> H(N*(N-1)/2);
/*N=4なら(12,13,14,23,24,34)で1になってたら連結を表す
100101なら連結してる辺は(1-2),(2-3),(3-4)*/

void output(){
    //M個のグラフの出力
    cout << N << endl;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < Graph.at(i).size(); j++){
            //i番目のグラフにはi個1連続で立っているようにする
            if(i > j){
                Graph.at(i).at(j) = 1;
            }
            cout << Graph.at(i).at(j);
        }
        cout << endl;
    }
}


int main(){
    cin >> M >> eps;
    
    Graph.resize(M, vector<int>(N*(N-1)/2, 0));
    output();

    for(int Query = 0; Query < 100; Query++){
        int count = 0;
        for(int i = 0; i < H.size(); i++){
            cin >> H.at(i);
            if(H.at(i) == 1) count++;
        }

        //解答
        cout << count << endl;
    }

    return 0;
}