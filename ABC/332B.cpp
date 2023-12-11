#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int K,G,M;
    cin >> K >> G >> M;

    int glass=0;
    int mag=0;
    for(int k = 0; k < K; k++){
        if(glass == G){
            glass = 0;
        }else if(mag == 0){
            mag = M;
        }else{
            if(mag >= G-glass){
                // 満たせる
                mag -= G-glass;
                glass = G;
            }else{
                glass += mag;
                mag = 0;
            }
        }

        // fprintf(stderr, "glass=%d, mag=%d\n", glass,mag);
    }

    cout << glass << " " << mag << endl;
    return 0;
}