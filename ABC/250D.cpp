#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> eratos(int M){
    vector<bool> table(M+1,true);
    table[0] = false; table[1] = false;
    for(int i = 2; i <= M; i++){
        if(table[i]){
            int cnt = 2; //cnt=1は素数iそのもの
            while(i*cnt <= M){
                table[i*cnt] = false;
                cnt++;
            }
        }
    }

    vector<int> ret;
    for(int i = 0; i < table.size(); i++){
        if(table[i]) ret.push_back(i);
    }

    return ret;
}

int main(){
    ll N; cin >> N;

    //p < qからk = p*q^3 < q^4
    //N <= 1e18よりq <= 1e6
    //1e6以下の素数をエラトステネスで
    int M = 1e6;
    vector<int> prime = eratos(M);

    //N以下になる(p,q)の組み合わせを求める
    ll ans = 0;
    int q_idx = prime.size()-1;
    for(int p_idx = 0; p_idx < prime.size(); p_idx++){
        //尺取りでq_idxを求める
        while(p_idx < q_idx){
            ll P = prime[p_idx];
            ll Q = prime[q_idx];
            double estimate = P*Q*Q*Q;
            if(estimate > 4e18 || P*Q*Q*Q > N){
                q_idx--;
            }else{
                break;
            }
        }
        
        //このとき、p < i < qを満たす全ての素数iに対してN以下を満たす。
        //もし p >= qであれば、これ以降 p < qになることはない
        if(p_idx >= q_idx) break;
        ans += q_idx-p_idx;
    }
    cout << ans << endl;
    return 0;
}