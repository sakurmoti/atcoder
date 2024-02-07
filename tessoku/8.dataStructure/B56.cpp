#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;

int main(){
    int N,Q; cin >> N >> Q;
    string S; cin >> S;

    // 前から文字列を見たときのハッシュ値と後ろから見たときのハッシュ値が同じであれば、同じ文字列とみなす
    // -> 回文になっていると判定
    const int B = 1009;
    vector<int> T(N+1,0);
    for(int i = 0; i < N; i++){
        T[i+1] = (int)S[i];
    }

    // ハッシュ関数はA56と同じ
    vector<mint> H(N+1, 0); // 前から見たとき
    for(int i = 1; i <= N; i++){
        H[i] = H[i-1] * B + T[i];
    }

    reverse(ALL(T));
    T.insert(T.begin(), 0);
    vector<mint> I(N+1, 0); // 後ろから見たとき
    for(int i = 1; i <= N; i++){
        I[i] = I[i-1] * B + T[i];
    }

    while(Q--){
        int L,R; cin >> L >> R;

        mint order = H[R] - mint(B).pow(R-L+1) * H[L-1]; // 順方向の[R,L]区間
        mint rev = I[N-L+1] - mint(B).pow((N-L+1) - (N-R+1) + 1) * I[(N-R+1)-1]; // 逆方向では[N-R+1, N-L+1]区間

        // printf("order = %d rev = %d\n",order.val(),rev.val());

        if(order.val() == rev.val()){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }


    
    return 0;
}