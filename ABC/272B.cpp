#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    /*flag[i][j]はiとjが舞踏会であったかどうか*/
    vector<vector<bool>> flag(N, vector<bool>(N, false));
    for(int i = 0; i < M; i++){
        int k;
        cin >> k;

        vector<int> x(k);
        for(int j = 0; j < k; j++){
            cin >> x.at(j);
        }

        for(int s = 0; s < k; s++){
            for(int t = 0; t < k; t++){
                flag.at(x.at(s)-1).at(x.at(t)-1) = true;
            }
        }
    }


    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(flag.at(i).at(j)){
            
            }else{
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}