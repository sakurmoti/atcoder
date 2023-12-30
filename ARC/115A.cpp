#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,M; cin >> N >> M;

    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    // 解答が異なる問題が奇数個あれば絶対に正解数は違う
    vector<int> T(N, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(S[i][j] == '1'){
                T[i]++;
            }
        }
    }

    ll odd = 0, even = 0;
    for(int i = 0; i < N; i++){
        if(T[i]%2 == 0) even++;
        else odd++;
    }

    cout << odd * even << endl;
    return 0;
}