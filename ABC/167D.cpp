#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N,K;
    cin >> N >> K;

    vector<int> A(N+1, -1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    //街1から閉路を見つけるまでシミュレーション
    vector<bool> visited(N+1, false);
    int now = 1;
    while(!visited[now]){
        visited[now] = true;
        now = A[now];
        K--;

        if(K <= 0){
            cout << now << endl;
            return 0;
        }
    }

    //閉路が一周何回で回れるか
    visited.assign(N+1, false);
    vector<int> path;
    int cnt=0;
    while(!visited[now]){
        path.push_back(now);
        visited[now] = true;
        now = A[now];
        cnt++;
    }

    cout << path.at(K%cnt) << endl;
    return 0;
}