#include <bits/stdc++.h>
using namespace std;

bool color[1010][1010];
bool seen[1010][1010];
int count;

int vec_dx[6] = {-1,-1,0,0,1,1};
int vec_dy[6] = {-1,0,-1,1,0,1};

void dfs(int x, int y){
    /*seenは訪問済みか確認するためのもの*/
    seen.at(y).at(x) = true; //訪問する

    //6方向を探索
    for(int i = 0; i < 6; i++){
        int dx = x + vec_dx.at(i);
        int dy = y + vec_dy.at(i);

        //場外なら無視
        if (dx < 0 || dx >= 1001 || dy < 0 || dy >= 1001) continue;

        // 移動先が探索済みの場合
        if(seen[dy][dx]){
            count--;
            continue;
        }

        // 再帰的に探索
        dfs(dx, dy);
    }
    
}

int main(){
    int N;
    cin >> N;
    vector<int> X(N),Y(N);
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
        color[Y[i]][X[i]] = true;
    }

    count = N;

    for(int i = 0; i < N; i++){
        dfs(X[i],Y[i]);
    }
    return 0;
}