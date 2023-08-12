#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int H,W,K;
    cin >> H >> W >> K;

    vector<vector<char>> C(H, vector<char>(W, '#'));
    for(auto &_v : C) for(auto &_vv : _v) cin >> _vv;
    
    //行だけ全探索
    int ans = 0;
    for(int i = 0; i < (1<<H); i++){
        bitset<10> select(i);
        if(select.count() > K) continue;

        vector<vector<char>> D = C;

        //行を選んで塗る
        for(int h = 0; h < H; h++){
            for(int w = 0; w < W; w++){
                if(select.test(h)){
                    D[h][w] = '#';
                }
            }
        }

        //盤面を列ごとに見る
        vector<pair<int, int>> row(W);
        for(int h = 0; h < H; h++){
            for(int w = 0; w < W; w++){
                row[w].second = w;
                if(D[h][w] == '.'){
                    row[w].first++;
                }
            }
        }

        //列のなかから塗る場所を選ぶ
        int remain = K - select.count();
        sort(row.rbegin(), row.rend());
        for(int k = 0; k < remain; k++){
            int idx = row[k].second;
            for(int h = 0; h < H; h++){
                D[h][idx] = '#';
            }
        }

        int cnt = 0;
        for(int h = 0; h < H; h++){
            for(int w = 0; w < W; w++){
                if(D[h][w] == '#') cnt++;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}