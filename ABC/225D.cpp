#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,Q;
    cin >> N >> Q;

    vector<pair<int, int>> train(N+1, make_pair(-1,-1)); //電車iの前後のみ保存する
    for(int i = 0; i < Q; i++){
        int cmd; cin >> cmd;
        int x,y;

        if(cmd == 1){
            cin >> x >> y;
            train[x].second = y;
            train[y].first = x;
        }

        if(cmd == 2){
            cin >> x >> y;
            train[x].second = -1;
            train[y].first = -1;
        }

        if(cmd == 3){
            cin >> x;
            //先頭を探す
            int now = x;
            while(train[now].first != -1){
                now = train[now].first;
                // cout << now << " ";
            }

            //先頭から後ろがなくなるまで
            vector<int> ans;
            while(train[now].second != -1){
                ans.push_back(now);
                now = train[now].second;
            }
            ans.push_back(now); //最後も忘れずに

            int M = ans.size();
            cout << M << " ";
            for(int j = 0; j < M; j++){
                cout << ans[j] << " \n"[j==M-1];
            }
        }
    }
    return 0;
}