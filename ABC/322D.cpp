#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void rotate(vector<string> &p){
    /*
    1,2,3    7,4,1
    4,5,6 を 8,5,2 にする
    7,8,9    9,6,3
    */

    vector<string> ret = p;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            ret[3-j][i] = p[i][j];
        }
    }
    p = ret;
}

bool check(vector<string> &field, vector<string> &p, int x, int y){
    //面に重複なく置けるか、枠外にブロックがないか
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(p[i][j] == '#'){
                int dx = x+j;
                int dy = y+i;
                if(! (0 <= dx && dx < 4 && 0 <= dy && dy < 4 ) ) return false;
                if(field[dy][dx] == '#') return false;
                field[dy][dx] = '#';
            }
        }
    }

    return true;
}

void solve(int now, vector<string> &field, vector<vector<string>> &P){
    // 配置
    if(now == 3){
        // 全ての面が埋められているか
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(field[i][j] != '#') return;
            }
        }
        cout << "Yes" << endl;
        exit(0);
    }

    for(int y = -3; y <= 3; y++){
        for(int x = -3; x <= 3; x++){
            auto next_field = field;
            bool can_put = check(next_field, P[now], x, y);
            if(can_put) solve(now+1, next_field, P);
        }
    }

    
}

int main(){
    vector<vector<string>> P(3);
    for(int i = 0; i < 3; i++){
        P[i].resize(4);
        for(auto &s : P[i]) cin >> s;
    }

    vector<string> f(4, "....");

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            // printf("i,j = {%d, %d}\n", i, j);
            solve(0, f, P);
            rotate(P[2]);
        }
        rotate(P[1]);
    }

    cout << "No" << endl;
    return 0;
}