#include <bits/stdc++.h>
using namespace std;

int N,endx,endy;
bool flag = false;
vector<int> A,B;

//(x,y)の情報とAのidx、前回の進んだ方向dirを引数に
void dfs(int x, int y, int idx, int dir){
    //printf("now x=%d y=%d\n",x,y);

    //flag = trueなら到達済み
    if(flag) return;

    //これ以上は移動できない
    if(idx == N){
        if(x == endx && y == endy){
            flag = true;
        }

        //cout << endl;
        return;
    }

    //残りの最大移動距離でゴールできるのか
    if(B.at(N-idx-1) < abs(x-endx)+abs(y-endy)){
        return;
    }
    
    //up=0
    if(dir%2 == 1) dfs(x, y+A.at(idx), idx+1, 0);

    //right=1
    if(dir%2 == 0) dfs(x+A.at(idx), y, idx+1, 1);

    //down=2
    if(dir%2 == 1) dfs(x, y-A.at(idx), idx+1, 2);

    //left=3
    if(dir%2 == 0) dfs(x-A.at(idx), y, idx+1, 3);
}

int main(){
    cin >> N >> endx >> endy;

    A.resize(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    //B[i]にはあと移動できる距離を入れる
    B.resize(N,0);
    B.at(0) = A.at(N-1);
    for(int i = 1; i < N; i++){
        B.at(i) = B.at(i-1) + A.at(N-i-1);
    }

    dfs(A.at(0), 0, 1, 1);

    cout << ( flag ? "Yes" : "No" ) << endl;
    return 0;
}