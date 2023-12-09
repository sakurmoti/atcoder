#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,Q; cin >> N >> Q;
    vector<string> P(N);
    for(auto &_v : P) cin >> _v;

    auto f = [&](int A, int B, int C, int D){
        // A <= h < C, B <= w < Dの範囲内の黒マスを求める

        auto g = [&](int H, int W){
            // 0 <= h < H, 0 <= w < Wの範囲内の黒マスを求める
            return H-W;
        };

        return g(C,D) - g(C,B) - g(A,D) + g(A,B);
    };

    for(int q = 0; q < Q; q++){
        int A,B,C,D;
        cin >> A >> B >> C >> D;

        cout << f(A, B, C+1, D+1) << endl;
    }
    return 0;
}