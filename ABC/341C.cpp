#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int H,W,N; cin >> H >> W >> N;
    string T; cin >> T;
    vector<string> S(H);
    for(auto &_v : S) cin >> _v;

    unordered_map<char, pair<int, int>> dxy;
    dxy['L'] = {0, -1};
    dxy['R'] = {0, +1};
    dxy['U'] = {-1, 0};
    dxy['D'] = {+1, 0};

    // 500 * 500 * 500 = 125,000,000
    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int ni = i;
            int nj = j;
            if(S[ni][nj] == '#') continue;

            bool flag = true;
            for(int k = 0; k < N; k++){
                ni += dxy[T[k]].first;
                nj += dxy[T[k]].second;

                if(S[ni][nj] == '#'){
                    flag = false;
                    break;
                }
            }

            if(flag) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}