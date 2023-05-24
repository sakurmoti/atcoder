#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

void solve(){
    int N;
    string S;
    cin >> N >> S;

    int cnt=0;
    vector<int> idx;
    for(int i = 0; i < N; i++){
        if(S.at(i) == '1'){
            cnt++;
            idx.push_back(i);
        }
    }

    if(cnt%2 == 1){
        //裏と裏、表と表、裏と表を選ぶどの場合でもcntの偶奇は一致
        cout << -1 << endl;
    
    }else if(cnt==2 && idx[0]+1 == idx[1]){
        //表が2個のみで、連続のとき
        if(N==3){
            //3個だと不可能
            cout << -1 << endl;
        
        }else if(N == 4){
            //4個だと真ん中で連番になってたら0110 -> 1100 -> 0101 -> 0000とする
            //端によっている(1100, 0011)なら最後か最初を使えばできる
            if(idx[0] == 1){
                cout << 3 << endl;
            
            }else{
                cout << 2 << endl;
            }

        }else{
            //5個以上なら最初か最後が必ず二個以上離れているのでそれを選べば2回
            cout << 2 << endl;
        }
    
    }else{
        //それ以外は適切に選べばcnt/2回でできる
        cout << cnt/2 << endl;

    }

    return;
}

int main(){
    int T;
    cin >> T;

    for(int i = 0; i < T; i++){
        solve();
    }
    return 0;
}