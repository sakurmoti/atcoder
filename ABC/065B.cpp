#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    vector<bool> visited(N+1, false);
    int now = 1;
    int ans = -1;
    while(!visited[2]){
        if(visited[now]) break;
        else visited[now] = true;

        now = A[now];
        ans++; //visited[2]がtrueになってもインクリメントされてしまうのでans=-1としている
    }

    if(visited[2]) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}