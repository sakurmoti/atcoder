//B39をO(N logN)で解く
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,D;
    cin >> N >> D;

    vector<vector<int>> X(D+1);
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;

        X.at(a).push_back(b); //a日目に始まる給料bの仕事
    }

    priority_queue<int, vector<int>, less<int>> pque; 
    int ans = 0;
    for(int i = 1; i <= D; i++){
        for(auto v : X.at(i)) pque.push(v); //i日目に始まる仕事をキューに追加

        if(!pque.empty()){
            ans += pque.top();
            pque.pop();
        }
    }
    
    cout << ans << endl;

    return 0;
}