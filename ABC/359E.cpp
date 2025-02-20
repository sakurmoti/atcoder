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
    vector<ll> H(N);
    for(auto &_v : H) cin >> _v;

    stack<pair<ll, ll>> wall; // 今までに超えた壁の位置と高さ

    ll now = 0;
    ll time = 0;
    vector<ll> ans(N);
    wall.push(make_pair(0,0));
    for(int i = 0; i < N; i++){
        // printf("------%d------\n",i);
        ll width = 1;
        while(!wall.empty() && wall.top().second <= H[i]){
            auto [f,s] = wall.top();
            wall.pop();

            width += f;
            time -= f*s; // 一度既に入ってた水を引いて後で纏めて足す
            // printf("width=%lld, f*s=%lld\n",width,f*s);
        }
        wall.push(make_pair(width, H[i]));

        time += H[i]*width;
        ans[i] = time+1;
    }

    for(auto &_v : ans) cout << _v << " "; cout << endl;
    return 0;
}