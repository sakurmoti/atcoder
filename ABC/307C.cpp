#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int Ha,Wa; cin >> Ha >> Wa;
    vector<string> A(Ha);
    for(auto &v : A) cin >> v;

    int Hb,Wb; cin >> Hb >> Wb;
    vector<string> B(Hb);
    for(auto &v : B) cin >> v;

    int Hc,Wc; cin >> Hc >> Wc;
    vector<string> C(Hc);
    for(auto &v : C) cin >> v;

    auto domain = [&](int x, int y) {return (0 <= x && x < Wc && 0 <= y && y < Hc);};

    for(int aX = -15; aX <= 15; aX++){
        for(int aY = -15; aY <= 15; aY++){
            // Aの開始位置(左上)を決める
            
            for(int bX = -15; bX <= 15; bX++){
                for(int bY = -15; bY <= 15; bY++){
                    bool ans = true;
                    // Bの開始位置(左上)を決める
                    
                    vector<vector<char>> D(Hc, vector<char>(Wc, '.'));
                    for(int i = 0; i < Ha; i++){
                        for(int j = 0; j < Wa; j++){
                            if(domain(aX+j,aY+i)){
                                D.at(aY+i).at(aX+j) = A[i][j];
                            
                            }else if(A[i][j] == '#'){
                                //黒のマスが外にあるのでダメ
                                ans = false;
                            }
                        }
                    }
                    for(int i = 0; i < Hb; i++){
                        for(int j = 0; j < Wb; j++){
                            if(domain(bX+j,bY+i)){
                                D.at(bY+i).at(bX+j) = B[i][j];
                            
                            }else if(B[i][j] == '#'){
                                ans = false;
                            }
                        }
                    }

                    //走査
                    for(int i = 0; i < Hc; i++){
                        for(int j = 0; j < Wc; j++){
                            if(D[i][j] != C[i][j]){
                                ans = false;
                            }
                        }
                    }

                    if(ans){
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