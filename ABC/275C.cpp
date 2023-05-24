#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int N = 9;

//二点の辺の長さを求める
int calc(int p, int q){
    return ((p%N)-(q%N))*((p%N)-(q%N)) + ((p/N)-(q/N))*((p/N)-(q/N));
}

bool isSquare(vector<int> D){
    if(D[0]==D[1] && D[1]==D[2] && D[2]==D[3] && D[3]==D[0]){ //4辺の長さが等しい
        if(D[4]==D[5]){ //対角線の長さが等しい
            if(D[4] == 2*D[0]){ //対角線 = 辺*sqrt(2)の両辺を二乗
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    //4点を全探索し、その集合が正方形になりうるか判定する
    //なお、点はx = a%N, y = a/Nとすれば綺麗に書けるはず
    int cnt = 0;
    for(int a = 0; a < N*N; a++){
        for(int b = a; b < N*N; b++){
            for(int c = b; c < N*N; c++){
                for(int d = c; d < N*N; d++){
                    if(!(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)) continue;

                    if(S[a%N][a/N] != '#' || S[b%N][b/N] != '#' || S[c%N][c/N] != '#' || S[d%N][d/N] != '#'){
                        continue;
                    }

                    int d1 = calc(a,b);
                    int d2 = calc(b,c);
                    int d3 = calc(c,d);
                    int d4 = calc(d,a);
                    int d5 = calc(a,c);
                    int d6 = calc(b,d);

                    vector<int> D = {d1,d2,d3,d4,d5,d6};
                    sort(D.begin(), D.end());

                    //printf("%d %d %d %d\n",a,b,c,d);
                    /*for(auto v : D) cout << v << " ";
                    cout << endl;*/

                    if(isSquare(D)){
                        cnt++;
                    }
                
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}