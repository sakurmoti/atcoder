//貪欲法
//通った都市から最も近い都市に移動する

#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> X(N+1),Y(N+1);
    for(int i = 1; i <= N; i++){
        cin >> X[i] >> Y[i];
    }

    vector<bool> isCome(N+1, false); //訪問したかどうか
    vector<int> ans; //訪問した順番
    int now = 1; //今いる街の番号
    isCome[1] = true;
    ans.push_back(now);

    //N個の都市を回る必要がある(N-1 回ループ)
    for(int i = 0; i < N-1; i++){
        double distance = 1e5; //次の街までの最短距離
        int idx; //最短距離の街の添え字

        //行先を決める(N 回ループ)
        for(int j = 1; j <= N; j++){
            if(isCome.at(j)){
                continue;

            }else{
                double tmp = sqrt(pow(X.at(now)-X.at(j), 2) + pow(Y.at(now)-Y.at(j), 2));
                if(tmp < distance){
                    distance = tmp;
                    idx = j;
                }
            }
        }

        ans.push_back(idx);
        now = idx;
        isCome.at(now) = true;
    }

    ans.push_back(1); //最後に1に帰ってくる
    for(auto v : ans){
        cout << v << endl;
    }

    return 0;
}