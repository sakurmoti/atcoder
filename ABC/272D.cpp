#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    /*dp[i][j]は(i,j)に行くことができる最小の回数
    dp[i+k][j+l] = dp[i][j] + 1  | k,lは(i-k)^2 + (j-l)^2 = Mを満たす数
    */

    //先に条件を満たす(k,l)のセットを求める
    vector<pair<int,int>> A;
    for(int k = 0; k*k <= M; k++){
        for(int l = 0; l*l <= M; l++){
            if(k*k + l*l == M){
                A.push_back({k,l});
                //printf("k=%d, l=%d\n", k,l);
            }
        }
    }

    vector<vector<int>> dp(N, vector<int>(N, 1e9));
    dp[0][0] = 0;
    for(int c = 0; c < 100; c++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k < A.size(); k++){
                    if(i - A.at(k).first >= 0 && j - A.at(k).second >= 0){
                        dp.at(i-A.at(k).first).at(j-A.at(k).second) 
                            = min(dp.at(i-A.at(k).first).at(j-A.at(k).second), dp.at(i).at(j) + 1);

                    }

                    if(i + A.at(k).first < N && j + A.at(k).second < N){
                        dp.at(i+A.at(k).first).at(j+A.at(k).second) 
                            = min(dp.at(i+A.at(k).first).at(j+A.at(k).second), dp.at(i).at(j) + 1);
                    }

                    if(i + A.at(k).first < N && j - A.at(k).second >= 0){
                        dp.at(i+A.at(k).first).at(j-A.at(k).second) 
                            = min(dp.at(i+A.at(k).first).at(j-A.at(k).second), dp.at(i).at(j) + 1);
                    }

                    if(i - A.at(k).first >= 0 && j + A.at(k).second < N){
                        dp.at(i-A.at(k).first).at(j+A.at(k).second) 
                            = min(dp.at(i-A.at(k).first).at(j+A.at(k).second), dp.at(i).at(j) + 1);
                    }
                }
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(dp.at(i).at(j) == 1e9){
                dp.at(i).at(j) = -1;
            }

            cout << dp.at(i).at(j);

            if(j != N-1) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}