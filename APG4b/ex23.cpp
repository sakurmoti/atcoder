#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    
    map<int, int> A;
    vector<int> data(N);
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        data.at(i) = temp;

        if(A.count(temp)){//もしkeyが存在しているなら
            //登場回数をインクリメント
            A.at(temp)++;
        }else{//していないなら
            //keyをtempとして登場回数1を追加
            A[temp] = 1;
        }

    }

    pair<int, int> ans(-1,0);
    for(int i = 0; i < N; i++){
        if(ans.second < A.at(data.at(i))){
            ans.first = data.at(i);
            ans.second = A.at(data.at(i));
        }
    }

    cout << ans.first << " " << ans.second << endl;

    return 0;
}