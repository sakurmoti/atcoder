#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    auto fact = [&](int x) -> int {
        int y = x;
        int ret = 1;
        for(int i = 2; i*i <= x; i++){        
            int bit = 0;
            while(y%i == 0){
                bit ^= 1;
                y/=i;
            }

            if(bit == 1){
                ret *= i;
            }
        }

        return ret*y;
    };

    vector<vector<int>> B(200'010);
    int zero = 0;
    for(int i = 0; i < N; i++){
        int res = fact(A[i]);
        // cout << res << endl;

        if(res == 0){
            zero++;
            continue;
        }
        
        B[res].push_back(i);
    }

    ll ans = 0;
    for(int i = 0; i < N; i++){
        int a = fact(A[i]);

        if(a==0){
            ans += (N-zero);
            zero--;
            continue;
        }

        int idx = B.at(a).end() - upper_bound(ALL(B.at(a)), i);
        ans += idx;
    }

    cout << ans << endl;
    return 0;
}