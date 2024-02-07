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

    /* 
    lからr文字目までをハッシュ化したときを以下で定義する(B進数を用いた)
    hash[l,r] := B^(r-l) * T[l] + B^(r-l-1) * T[l+1] + ... + B^0 * T[r]
    
    このとき hash[1,K] := B^(K-1) * T[1] + B^(K-2) * T[2] + ... + B^0 * T[K]
    であることから、hash[1,i] = B * hash[1,i-1] + T[i]
    
    また、hash[l,r] はhash[1,r]の定義式から
    hash[1, r] = B^(r-1) * T[1] + ... + B^(r-l+1) * T[l-1] + B^(r-l) * T[l] + ... + B^0 * T[r]
               = B^(r-1) * T[1] + ... + B^(r-l+1) * T[l-1] + hash[l, r]
               = B^(r-l+1) * hash[1, l-1] + hash[l, r]
    ゆえに
    hash[l,r] = hash[1, r] - B^(r-l+1) * hash[1,l-1]
    
    よってhash[1, K]を前計算し、Bの累乗を繰り返し二乗法などで高速に求めればよい
    */

    vector<int> T(N+1,0); //1-idxで扱う
    for(int i = 0; i < N; i++){
        T[i+1] = (int)S[i];
    }

    const int B = 100;

    // H[i] = hash[1,i]
    vector<mint> H(N+1, 0);
    H[0] = mint(0);
    for(int i = 1; i <= N; i++){
        H[i] = B * H[i-1] + T[i];
    }

    while(Q--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        
        mint q1 = H[b] - mint(B).pow(b-a+1) * H[a-1];
        mint q2 = H[d] - mint(B).pow(d-c+1) * H[c-1];

        // printf("q1 = %d, q2 = %d\n",q1.val(), q2.val());

        if(q1.val() == q2.val()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}