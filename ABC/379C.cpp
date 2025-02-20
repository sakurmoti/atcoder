#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll N,M; cin >> N >> M;
    vector<pair<ll, ll>> A(M);
    ll all = 0;
    for(int i = 0; i < M; i++){
        cin >> A[i].first;
    }
    for(int i = 0; i < M; i++){
        cin >> A[i].second;
        all += A[i].second;
    }

    sort(ALL(A));

    if(all != N){
        cout << -1 << endl;
        return 0;
    }

    if(A[0].first != 1){
        cout << -1 << endl;
        return 0;
    }
    A.push_back(make_pair(N+1, -1));
    
    stack<pair<ll, ll>> stk;
    ll ans = 0;
    for(int i = 0; i < M; i++){
        auto [now, B] = A[i];
        auto [next, buf] = A[i+1];

        ll cnt = next - now; // [now, next)の間の石を埋める
        stk.push(A[i]);

        bool flag = false;
        ll ok = 0; // okまで埋めた

        while(!stk.empty()){
            auto [x,b] = stk.top(); // 位置xに石がb個ある
            stk.pop();

            // printf("now = %lld, use of idx :%lld  size : %lld\n", now, x, b);

            if(cnt - b <= 0){ // この石で足りるか

                // 操作回数は末項now-x+cnt-1, 初項now-x+ok, 公差1の等差数列の和
                ll a1 = now-x+ok;
                ll an = now-x+ok+cnt-1;
                ll sum = ( (a1 + an) * (cnt)) /2;

                ans += sum;

                stk.push(make_pair(x, b-cnt));
                flag = true;

                // printf("a1 = %lld, an = %lld, cnt = %lld, \tsum = %lld\n", a1, an, cnt, sum);
                break;
            }else{
                ll a1 = now-x+ok;
                ll an = now-x+ok+b-1;
                ll sum = ( (a1 + an) * (b)) /2;

                ans += sum;

                cnt -= b;
                ok += b;

                // printf("if2: a1 = %lld, an = %lld, cnt = %lld, \tsum =%lld\n", a1, an, cnt, sum);
            }
        }

        if(!flag){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;

    return 0;
}