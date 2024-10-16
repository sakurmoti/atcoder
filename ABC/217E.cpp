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

int main(){
    int Q; cin >> Q;
    
    priority_queue<int, vector<int>, greater<int>> pque;
    deque<int> deq;
    while(Q--){
        int q,x; cin >> q;
        if(q==1){
            cin >> x;
            deq.push_back(x);
        
        }else if(q==2){
            if(!pque.empty()){
                x = pque.top();
                pque.pop();
            }else{
                x = deq.front();
                deq.pop_front();
            }
            cout << "\t";
            cout << x << endl;

        }else{
            while(!deq.empty()){
                pque.push(deq.front());
                deq.pop_front();
            }
        }
    }
    return 0;
}