#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    vector<pair<int, int>> query;
    for(int i = 0; i < N; i++){
        while(A[i] != i+1){
            int idx = A[i];
            swap(A[i], A[idx-1]);
            
            query.push_back(make_pair(i+1, idx));
        }
    }

    // for(auto &_v : A) cout << _v << " "; cout << endl;

    cout << query.size() << endl;
    for(auto [f,s] : query){
        cout << f << " " << s << endl;
    }
    return 0;
}