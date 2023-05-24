#include <bits/stdc++.h>
using namespace std;

//メモ化再帰 再帰関数において一度計算した値をメモして計算量を減らすこと
/*f(x)をxを始点としたときの最長経路とする
このとき、xが葉ならf(x)=0 そうでないならf(y)+1 (ただしyはx->yの辺があるようなy)
dp[x]にf(x)を入れていく*/
vector<int> dp; //f(x)の値をメモする配列
vector<vector<int>> G; //グラフを形成
vector<bool> flag; //訪れたことがあるかどうかを記憶する配列
int f(int x){
    if(flag.at(x)){
        return dp.at(x); //訪れたことがあるなら計算済み
    }

    flag.at(x) = true; //xに訪れたのでtrueに

    int dist = 0; //距離
    for(int i = 0; i < G.at(x).size(); i++){
        //xからyへの辺があるようなyを全探索
        //閉回路がないので必ずいつかは葉にたどり着く。ゆえに無限ループはしない
        dist = max(dist, f(G.at(x).at(i))+1);
    }

    dp.at(x) = dist; //xが葉ならdistが0のままdpに入るので正しく動く
    return dp.at(x);
}

int main(){
    int N,M;
    cin >> N >> M;

    dp.resize(N+1, -10);
    flag.resize(N+1, false);
    G.resize(N+1, vector<int>());
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;

        G.at(a).push_back(b);
    }

    for(int i = 1; i <= N; i++){
        f(i);
    }

    int ans=0;
    for(int i = 1; i <= N; i++){
        //printf("dp[%d] = %d\n",i,dp[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}