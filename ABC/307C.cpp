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

    for(int aX = 0; aX <= 20; aX++){
        for(int aY = 0; aY <= 20; aY++){
            // Aの開始位置(左上)を決める
            
            for(int bX = 0; bX <= 20; bX++){
                for(int bY = 0; bY <= 20; bY++){
                    // Bの開始位置(左上)を決める
                    
                    vector<vector<char>> D(50, vector<char>(50, '.'));
                    for(int i = 0; i < Ha; i++){
                        for(int j = 0; j < Wa; j++){
                            D.at(aY+i).at(aX+j) = A.at(i).at(j);
                        }
                    }
                    for(int i = 0; i < Hb; i++){
                        for(int j = 0; j < Wb; j++){
                            //if文を付けないとAのシートを上書きしてしまうことに注意
                            if(B[i][j] == '#') D.at(bY+i).at(bX+j) = B.at(i).at(j);
                        }
                    }

                    //走査
                    bool ans = true;
                    for(int i = 0; i < 50; i++){
                        for(int j = 0; j < 50; j++){
                            if( (10 <= i && i < 10+Hc) && (10 <= j && j < 10+Wc) ){
                                if(D.at(i).at(j) != C.at(i-10).at(j-10)){
                                    ans = false;
                                }
                            }else{
                                if(D.at(i).at(j) == '#') ans = false;
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