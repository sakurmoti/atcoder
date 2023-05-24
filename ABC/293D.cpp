#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,M;
    cin >> N >> M;

    dsu uf(2*N);
    //ロープの赤と青は元から繋がっている
    //赤が偶数、青が奇数とする
    for(int i = 0; i < N; i++){
        uf.merge(2*i, (2*i)+1);
    }

    int X=0,Y=0;
    for(int i = 0; i < M; i++){
        int a,c;
        char b,d;

        cin >> a >> b >> c >> d;

        //0-idxに
        a--; c--;
        
        //頂点番号に直す
        a *= 2;
        c *= 2;

        //色の補正
        if(b=='B') a++;
        if(d=='B') c++;
    
        //閉路検出
        if(uf.same(a,c)){
            X++;
        }

        //マージ
        uf.merge(a,c);
    }

    //グループを数える
    auto hoge = uf.groups();
    /*for(auto x : hoge){
        for(auto y : x) cout << y << " ";
        cout << endl;
    }*/

    Y = hoge.size() - X;
    cout << X << " " << Y << endl;
    return 0;
}