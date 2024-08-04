#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,K; cin >> N >> K;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    int r = 0;
    int ans = 0;
    int cnt = 0;
    multiset<int> mst;
    for(int l = 0; l < N; l++){
        while(r < N){
            if(mst.find(A[r]) == mst.end()){
                if(cnt < K) cnt++;
                else break;
            }

            mst.insert(A[r]);
            r++;
        }

        if(chmax(ans, r-l)){
            // cout << l << " " << r << endl;
        }

        mst.erase(mst.find(A[l]));
        if(mst.find(A[l]) == mst.end()) cnt--;
    }

    cout << ans << endl;
    return 0;
}