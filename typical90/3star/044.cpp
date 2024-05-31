#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,Q; cin >> N >> Q;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    int pos = 0;
    while(Q--){
        int t,x,y;
        cin >> t >> x >> y;
        x--; y--;

        if(t == 1){
            swap(A[ ((x+pos)%N + N) %N], A[((y+pos)%N + N) % N]);

        }else if(t == 2){
            pos--;

        }else{
            cout << A[((x+pos)%N + N) %N] << endl;

        }

        // for(int i = 0; i < N; i++){
        //     cout << A[(i+pos) % N] << " ";
        // }cout << "\n";
    }
    return 0;
}