#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x, y;};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

#include <atcoder/all>
using namespace atcoder;
using S = char;
S op(S a, S b){return min(a,b);}
S e(){return (char)('z'+1);}

int main(){
    int N,K; cin >> N >> K;
    vector<char> T(N);
    map<char, queue<int>> idx;
    for(int i = 0; i < N; i++){
        cin >> T[i];
        idx[T[i]].push(i);
    }

    // for(auto [k,v] : idx){
    //     auto cp = v;
    //     cout << k << " " ;
    //     while(!cp.empty()){
    //         cout << cp.front() << " ";
    //         cp.pop();
    //     }
    //     cout << endl;
    // }

    segtree<S, op, e> seg(T);

    string ans = "";
    int l = 0;
    for(int i = 0; i < K; i++){
        int r = N-K+i+1;
        
        while(true){
            // printf("[l,r) = [%d, %d)\n",l,r);
            char c = seg.prod(l, r);
            if(l >= idx[c].front()+1){
                
                idx[c].pop();
                continue;
            }
            l = (idx[c].front()+1);
            idx[c].pop();
        
            ans += c;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}