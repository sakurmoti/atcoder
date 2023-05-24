#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    vector<string> S(H),T(H);
    for(int i = 0; i < H; i++) cin >> S.at(i);
    for(int j = 0; j < H; j++) cin >> T.at(j);

    //Sの列とTの列が同じならよい
    map<string, int> S_column;
    for(int i = 0; i < W; i++){
        string column;
        for(int j = 0; j < H; j++){
            column += S.at(j).at(i);
        }
        S_column[column]++;
    }

    for(int i = 0; i < W; i++){
        string column;
        for(int j = 0; j < H; j++){
            column += T.at(j).at(i);
        }

        if(S_column.count(column)){
            if(S_column.at(column) > 0){
                S_column.at(column)--;
            
            }else{
                cout << "No" << endl;
                return 0;
            }

        }else{
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}