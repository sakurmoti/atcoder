#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,K;
    cin >> N >> K;

    string S;
    cin >> S;

    //Yの間隔を調べて(YXXYのような)その間隔が小さい順に間のXを反転する
    //間隔を全てひっくり返せたら余った分は..?
    vector<int> between;    
    int cnt = 0;
    int sum = 0;
    for(int i = 0; i < N; i++){
        if(S.at(i) == 'X'){
            cnt++;
        
        }else{
            if(cnt != 0){
                sum += cnt;
                between.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if(cnt != 0){
        sum += cnt;
        between.push_back(cnt);
        cnt = 0;
    }
    
    if(sum > K){
        //Xの数がKより大きいのでXの全てをYにすればよい
        sort(between.begin(), between.end());

        for(int i = 0; i < between.size(); i++){
            if(sum - between.at(i) >= 0){
                

            }else{

            }
        }
    }

    return 0;
}