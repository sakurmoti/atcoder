#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int H,W; cin >> H >> W;
    
    vector<vector<ll>> A(H, vector<ll>(W)), B(H, vector<ll>(W));
    for(auto &_v : A) for(auto &_vv : _v) cin >> _vv;
    for(auto &_v : B) for(auto &_vv : _v) cin >> _vv;

    // 行と列は分けて考える
    vector<int> h(H), w(W);
    iota(ALL(h), 0);
    iota(ALL(w), 0);

    int ans = 1e9;
    do{
        do{
            bool flag = true;
            for(int i = 0; i < H; i++){
                for(int j = 0; j < W; j++){
                    if(A[h[i]][w[j]] != B[i][j]){
                        flag = false;
                        break;
                    }
                }
            }
            
            if(flag){
                int h_cnt = 0;
                int w_cnt = 0;

                vector<int> buf = h;
                for(int i = 0; i < H; i++){
                    for(int j = 0; j < H-i-1; j++){
                        if(buf[j] > buf[j+1]){
                            h_cnt++;
                            swap(buf[j], buf[j+1]);
                        }
                    }
                }

                buf = w;
                for(int i = 0; i < W; i++){
                    for(int j = 0; j < W-i-1; j++){
                        if(buf[j] > buf[j+1]){
                            w_cnt++;
                            swap(buf[j], buf[j+1]);
                        }
                    }
                }

                ans = min(ans, h_cnt+w_cnt);
            }

        }while(next_permutation(ALL(w)));
    }while(next_permutation(ALL(h)));


    if(ans > 1e8) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}