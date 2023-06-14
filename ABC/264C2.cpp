#include <bits/stdc++.h>
using namespace std;

int main(){
    int H1,W1;
    cin >> H1 >> W1;
    vector<vector<int>> A(H1,vector<int>(W1));
    for(int i = 0; i < H1; i++){
        for(int j = 0; j < W1; j++){
            cin >> A[i][j];
        }
    }

    int H2,W2;
    cin >> H2 >> W2;
    vector<vector<int>> B(H2,vector<int>(W2));
    for(int i = 0; i < H2; i++){
        for(int j = 0; j < W2; j++){
            cin >> B[i][j];
        }
    }
    
    // bit全探索 O(2^H1 * 2^W1 * H1 * W1) ~= O(10^3 * 10^3 * 10 * 10)
    for(int i = 0; i < (1 << H1); i++){
        for(int j = 0; j < (1 << W1); j++){
            vector<vector<int>> C;
            bitset<20> h(i);
            bitset<20> w(j);

            for(int k = 0; k < H1; k++){
                vector<int> buf;
                for(int l = 0; l < W1; l++){
                    if(h.test(k) && w.test(l)){
                        buf.push_back(A[k][l]);
                    }
                }
                if(buf.size() != 0)C.push_back(buf);
            }

            if(B==C){
                cout << "Yes" << endl;
                return 0;
            }

            // if(C.size() == H2 && C[0].size() == W2){
            //     for(int k = 0; k < C.size(); k++){
            //         for(int l = 0; l < C[k].size(); l++){
            //             cout << C[k][l];
            //         }
            //         cout << endl;
            //     }
            //     cout << endl;
            // }
        }
    }

    cout << "No" << endl;
    return 0;
}