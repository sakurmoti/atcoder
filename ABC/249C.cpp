#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,K; cin >> N >> K;
    vector<string> S(N);
    for(auto &_v : S) cin >> _v;

    int ans = 0;
    for(int b = 0; b < (1 << N); b++){
        bitset<15> bits(b);

        map<char, int> dict;
        for(int i = 0; i < N; i++){
            if(bits.test(i)){
                for(int j = 0; j < S[i].size(); j++){
                    dict[S[i][j]]++;
                }
            }
        }

        int cnt = 0;
        for(auto [k,v] : dict){
            if(v == K){
                cnt++;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}