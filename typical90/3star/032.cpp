//これむず～～～い
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A.at(i).at(j);
        }
    }

    int M;
    cin >> M;
    vector<int> X(M),Y(M);
    for(int i = 0; i < M; i++){
        cin >> X.at(i) >> Y.at(i);
    }

    //順番を決めるための数列
    vector<int> P;
    for(int i = 1; i <=N; i++){
        P.push_back(i);
    }

    do{
        int time=0;

        //iは走るランナーを選ぶ
        for(int i = 0; i < N; i++){
            //jは走る区間を選ぶためのもの。実際はPのindexを選んで動かす
            int j = P.at(i);

            time += A.at(i).at(j);
        }

    }while(next_permutation(P.begin(), P.end()));


    return 0;
}