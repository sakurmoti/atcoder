#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int h1,h2,h3,w1,w2,w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    // 左上4つさえ決めればあとは計算可能
    int ans = 0;
    for(int xx = 1; xx <= 30; xx++){
        for(int xy = 1; xy <= 30; xy++){
            for(int yx = 1; yx <= 30; yx++){
                for(int yy = 1; yy <= 30; yy++){
                    int xz = h1 - xx - xy;
                    int yz = h2 - yx - yy;
                    int zx = w1 - xx - yx;
                    int zy = w2 - xy - yy;

                    if(xz <= 0 || yz <= 0 || zx <= 0 || zy <= 0){
                        continue;
                    }

                    int zz = w3 - xz - yz;

                    if(zz > 0 && zx + zy + zz == h3){
                        ans++;
                    }

                    // fprintf(stderr, "%d %d %d\n", xx,xy,xz);
                    // fprintf(stderr, "%d %d %d\n", yx,yy,yz);
                    // fprintf(stderr, "%d %d %d\n\n", zx,zy,zz);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}