#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N,M;
    cin >> N >> M;

    //マス0, マスN+1は青色とする
    vector<int> A(M+2);
    A[0] = 0; A[M+1] = N+1;
    for(int i = 1; i <= M; i++){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    //青の幅が最小に合わせるのが最適
    vector<int> white;
    for(int i = 1; i <= M+1; i++){
        if(A[i] - A[i-1] -1 == 0) continue;
        white.push_back(A[i] - A[i-1] -1);
    }

    sort(white.begin(), white.end()); //幅0 = 連続は除いている
    // for(auto &v : C) cout << v << ' ';

    int C = white.size();
    if(C == 0){
        //全て青色
        cout << 0 << endl;
        return 0;
    }

    double width = white[0]; //ハンコの最適な大きさ
    int ans = 0;
    for(int i = 0; i < C; i++){
        ans += ceil(white[i]/width);
    }

    cout << ans << endl;

    return 0;
}