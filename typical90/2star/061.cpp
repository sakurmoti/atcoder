#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int Q; cin >> Q;

    deque<int> deq;
    while(Q--){
        int t,x; cin >> t >> x;

        if(t == 1){
            deq.push_front(x);
        }else if(t == 2){
            deq.push_back(x);
        }else{
            x--;
            cout << deq[x] << endl;
        }
    }
    return 0;
}