#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M; cin >> N >> M;

    vector<int> P(N), C(N);
    vector<vector<bool>> F(N, vector<bool>(110, false));
    for(int i = 0; i < N; i++){
        cin >> P[i] >> C[i];
        for(int j = 0; j < C[i]; j++){
            int f; cin >> f;
            F[i][f] = true;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(P[i] >= P[j]){
                //Pi >= Pjである
                bool flag2 = true;
                bool flag3 = false;
                for(int k = 1; k <= M; k++){
                    //j番目はi番目の機能をすべて持つ
                    if(F[i][k] == true && F[j][k] == false) flag2 = false;
                    if(F[i][k] == false && F[j][k] == true) flag3 = true;
                }

                if(flag2){
                    if(flag3 || P[i] > P[j]){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}