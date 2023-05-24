#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<char>> S(10, vector<char>(10));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> S.at(i).at(j);
        }
    }

    int A,B,C,D;

    bool flag = true;
    for(int y = 0; y < 10 && flag; y++){
        for(int x = 0; x < 10 && flag; x++){
            if(S.at(y).at(x) == '#'){
                //初めて#が出現したところ = 左上になる
                //0-indexを1-indexに直すように 
                A = y+1;
                C = x+1;
                flag = false;
            }
        }
    }

    for(int i = C-1; i <= 10; i++){
        if(i == 10) D = 10;
        else if(S.at(A-1).at(i) == '.'){
            //左上から右に見ていって.がでたら終わり。出なかったらDは右端になる
            D = i;
            break;
        }
    }

    for(int i = A-1; i <= 10; i++){
        if(i == 10) B = 10;
        else if(S.at(i).at(C-1) == '.'){
            //左上から下に見ていって.がでたら終わり。出なかったらBは下端になる
            B = i;
            break;
        }
    }

    printf("%d %d\n%d %d",A,B,C,D);
    return 0;
}