#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N+1);
    vector<int> ans(N+1, 0);
    for(int i = 2; i <= N; i++) cin >> A[i];

    //地位順に番号がつけられているので、Nから順に見ていく
    for(int i = N; i >= 2; i--){
        int parent = A[i];
        ans[parent] += (ans[i]+1); //iの部下 + i本人
    }

    for(int i = 1; i <= N; i++){
        cout << ans[i] << " ";
    }
    return 0;
}