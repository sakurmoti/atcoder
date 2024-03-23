#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isRange(int x, int l, int r){
    return (l <= x) && (x < r);
}

int main(){
    int H,W; cin >> H >> W;
    vector<string> S(H);
    for(auto &v : S) cin >> v;

    dsu d(H*W);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#'){
                for(int k = 0; k < 4; k++){
                    int di = i + dy[k];
                    int dj = j + dx[k];
                    if(isRange(di, 0, H) && isRange(dj, 0, W) && S[di][dj] == '#'){
                        d.merge(i*W + j, di*W + dj);
                    }
                }
            }else{
                for(int k = 0; k < 4; k++){
                    int di = i + dy[k];
                    int dj = j + dx[k];
                    if(isRange(di, 0, H) && isRange(dj, 0, W) && S[di][dj] == '.'){
                        d.merge(i*W + j, di*W + dj);
                    }
                }
            }
        }
    }

    // 緑の連結成分だけ数える
    int green = 0;
    for(auto u : d.groups()){
        int v = u[0];
        if(S[v/W][v%W] == '#') green++;
    }

    // int red = d.groups().size() - green;
    // fprintf(stderr, "green = %d, red = %d\n", green, red);

    // 赤を書き換えていく
    mint gr(0), cnt(0);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] != '.') continue;
            cnt++; // 制約より0割りはない


            set<int> leaders;
            for(int k = 0; k < 4; k++){
                int di = i + dy[k];
                int dj = j + dx[k];
                
                if(isRange(di,0,H) && isRange(dj,0,W) && S[di][dj] == '#'){
                    leaders.insert(d.leader(di*W + dj));
                }
            }

            if(leaders.size() == 0){
                // 周りに赤しかない = 新しい連結成分
                gr += green + 1;
            }else if(leaders.size() == 1){
                // 連結成分変わらず
                gr += green;

            }else{
                // 連結成分同士をくっつける
                gr += green - (leaders.size() -1);
            }

            // fprintf(stderr, "gr = %d , leaders = %d\n", gr.val(), leaders.size());

        }
    }

    // cout << gr.val() << " " << cnt.val() << endl;
    cout << (gr/cnt).val() << endl;
    return 0;
}