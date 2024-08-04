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
    vector<int> W(N);
    for(auto &_v : W) cin >> _v;

    vector<priority_queue<int, vector<int>, greater<int>>> box(N+1);
    vector<int> cnt(N+1, 0);
    for(int i = 0; i < N; i++){
        int a = A[i];
        int w = W[i];

        box[a].push(w);
        cnt[a] += 1;
    }

    ll sum = 0;
    for(int i = 1; i <= N; i++){
        while(cnt[i] > 1){
            sum += box[i].top();
            box[i].pop();
            cnt[i]--;
        }
    }

    cout << sum << endl;
    return 0;
}