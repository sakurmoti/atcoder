#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> C(H, vector<char>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> C[i][j];
        }
    }

    //色はa~zの26色なのを利用する
    int M = 26;
    vector<vector<int>> row(H, vector<int>(M,0)), column(W, vector<int>(M,0));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int color = C[i][j] - 'a';
            row[i][color]++;
            column[j][color]++;
        }
    }

    int X = W;
    int Y = H;
    vector<bool> deleted_row(H, false), deleted_column(W, false);
    for(int _ = 0; _ < H+W; _++){
        //全ての行と列に対して探索

        vector<pair<int, int>> del_row,del_column; //削除する行と列を記憶。逐次消すとY>1の条件で引っかかってしまうのでダメ

        for(int i = 0; i < H; i++){
            if(deleted_row[i]) continue; //削除済みならスキップ

            for(int j = 0; j < M; j++){
                //全ての色に対して走査
                
                if(row[i][j] == X && X > 1){
                    //この行を削除する
                    del_row.push_back(make_pair(i,j));
                }
            }
        }

        for(int i = 0; i < W; i++){
            if(deleted_column[i]) continue;

            for(int j = 0; j < M; j++){
                if(column[i][j] == Y && Y > 1){
                    del_column.push_back(make_pair(i,j));
                }
            }
        }

        for(auto v : del_row){
            deleted_row[v.first] = true; //消したことを記録
            for(int i = 0; i < W; i++){
                column[i][v.second]--;
            }
            Y--;
        }

        for(auto v : del_column){
            deleted_column[v.first] = true;
            for(int i = 0; i < H; i++){
                row[i][v.second]--;
            }
            X--;
        }
    }

    cout << X * Y << endl;

    return 0;
}