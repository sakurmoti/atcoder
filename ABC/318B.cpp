#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<vector<bool>> S(110, vector<bool>(110, false));
    for(int i = 0; i < N; i++){
        int A,B,C,D;
        cin >> A >> B >> C >> D;

        for(int j = A; j < B; j++){
            for(int k = C; k < D; k++){
                S[j][k] = true;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            if(S[i][j]) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}