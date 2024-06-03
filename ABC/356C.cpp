#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,M,K; cin >> N >> M >> K;
    vector<pair<vector<int>, bool>> A(M);
    for(int i = 0; i < M; i++){
        int C; cin >> C;
        vector<int> k(C);
        for(int j = 0; j < C; j++){
            cin >> k[j];
            k[j]--;
        }

        A[i].first = k;
        char r; cin >> r;
        if(r == 'o') A[i].second = true;
        else A[i].second = false;
    }

    ll ans = 0;
    for(int i = 0; i < (1<<N); i++){
        bitset<20> keys(i);
        bool isok = true;

        for(int j = 0; j < M; j++){
            auto[st, r] = A[j];
            int cnt = 0;
            for(auto v : st){
                if(keys.test(v)){
                    cnt++;
                }
            }

            if(!( (cnt >= K && r) || (cnt < K && !r) ) ){
                isok = false;
            }
        }

        if(isok) ans++;
    }

    cout << ans << endl;
    return 0;
}