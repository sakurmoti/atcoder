#include <bits/stdc++.h>
using namespace std;
using ll = long long;


bool check(vector<vector<char>> &A, vector<string> &B){
    for(int stH = 0; stH < A.size(); stH++){
        for(int stW = 0; stW < A[0].size(); stW++){
            
            bool flag = true;
            for(int i = 0; (i < B.size())&&flag; i++){
                for(int j = 0; (j < B[0].size())&&flag; j++){
                    int h = stH + i;
                    int w = stW + j;

                    if(h < 0 || w < 0 || A.size() <= h || A[0].size() <= w){
                        flag = false;
                        continue;
                    }

                    if(A.at(h).at(w) != B.at(i).at(j)){
                        flag = false;
                    }
                }
            }

            if(flag) return true;
        }
    }

    return false;
    
}

int main(){
    int Ha,Wa; cin >> Ha >> Wa;
    vector<string> A(Ha);
    for(auto &v : A) cin >> v;

    int Hb,Wb; cin >> Hb >> Wb;
    vector<string> B(Hb);
    for(auto &v : B) cin >> v;

    int Hx,Wx; cin >> Hx >> Wx;
    vector<string> X(Hx);
    for(auto &v : X) cin >> v;

    //Aを動かす必要はなく、Bのみ動かして全探索
    for(int stH = -20; stH < 20; stH++){
        for(int stW = -20; stW < 20; stW++){
            
            for(int i = 0; i < Hb; i++){
                //空間CにAを貼り付け
                vector<vector<char>> C(100,vector<char>(100, '.'));
                for(int h = 0; h < Ha; h++){
                    for(int w = 0; w < Wa; w++){
                        C[50+h][50+w] = A[h][w];
                    }
                }

                //空間CにBを貼り付け
                for(int j = 0; j < Wb; j++){
                    int h = stH + i + 50;
                    int w = stW + j + 50;
                    if(C.at(h).at(w) == '.') C[h][w] = B[i][j];
                }

                if(check(C,X)){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}