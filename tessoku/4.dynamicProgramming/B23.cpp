#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point{
    int x;
    int y;
};

double cost(point z1, point z2){
    int X = (z1.x - z2.x)*(z1.x - z2.x);
    int Y = (z1.y - z2.y)*(z1.y - z2.y);
    return sqrt(X+Y);
}

int main(){
    int N; cin >> N;
    vector<point> T(N);
    for(int i = 0; i < N; i++){
        cin >> T[i].x >> T[i].y;
    }

    //dp[S][i] := 既に訪問した集合をS、現在位置がiとしたときの最短経路
    //最終的に一つのパスが出来るが、そのどこから始めても一般性を失わないので、都市0から始めることとする。
    //従ってdp[0][0] = 0;
    vector<vector<double>> dp(1<<N, vector<double>(N, 1e9));
    dp[0][0] = 0;
    for(int b = 0; b < (1<<N); b++){ //訪問した都市の集合
        for(int i = 0; i < N; i++){ //今いる都市
            for(int j = 0; j < N; j++){ //次に行く都市
                if((b & (1<<j)) != 0){
                    //次に行く都市が訪問済みならskip
                    // printf("b=%d, j=%d, b&j = %d\n",b,j, b&j);
                    continue;
                }
                int s = b | (1<<j);
                dp[s][j] = min(dp[s][j], dp[b][i] + cost(T[i], T[j]));
            }
        }
    }

    cout << fixed << setprecision(10) << dp[(1<<N)-1][0] << endl;
    return 0;
}