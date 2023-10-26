#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N; cin >> N;

    //a^2 * b * c^2なので最大のありうる素数は2^2 * 3 * c^2 <= 1e12 より c^2 <= 1e11 <-> x <= 1e6
    int M = 4e5;
    auto make_prime = [&](){
        vector<bool> p(M, true);
        p[0] = false;
        p[1] = false;
        for(ll i = 2; i*i <= M; i++){
            if(p[i] == false) continue;
            
            int cnt = 2;
            while(i*cnt < M){
                p[i*cnt] = false;
                cnt++;
            }
        }

        vector<ll> ret;
        for(int i = 0; i < M; i++){
            if(p[i]){
                ret.push_back(i);
            }
        }

        return ret;
    };

    vector<ll> prime = make_prime();
    int P = prime.size();
    // cout << P << endl;

    ll ans = 0;
    for(int i = 0; i < P; i++){
        for(int j = i+1; j < P; j++){
            for(int k = j+1; k < P; k++){
                // printf("%d, %d, %d\n", prime[i], prime[j], prime[k]);
                ll t = prime[i] * prime[i] * prime[j];
                if(t > N) break;

                t *= prime[k];
                if(t > N) break;

                t *= prime[k];
                if(t > N) break;

                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}