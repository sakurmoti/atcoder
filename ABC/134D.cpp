#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> A(N+1, 0);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    // 実際に箱に入っている個数(0 or 1)
    vector<int> B(N+1, 0);

    // 上から順に決めると、i以上の値は全て決めることができる
    // N/2まではAと同じ
    for(int i = N; i >= 1; i--){
        int sum = 0;
        for(int j = 2; i*j <= N; j++){
            sum += B[i*j];
        }

        // sum + B[i]の偶奇がA[i]に合うようにBを調整
        if(sum%2 == A[i]) B[i] = 0;
        else B[i] = 1;
    }

    vector<int> ans;
    for(int i = 1; i <= N; i++){
        // cout << B[i] << " ";
        if(B[i] == 1){
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for(int _i = 0; _i < ans.size(); _i++){
        cout << ans[_i] << " \n"[_i == ans.size()-1];
    }
    return 0;
}