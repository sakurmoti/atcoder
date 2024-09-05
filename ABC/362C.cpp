#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    vector<pair<ll, ll>> A(N);
    ll Mini = 0, Maxi=0;
    for(int i = 0; i < N; i++){
        cin >> A[i].first >> A[i].second;
        Mini += A[i].first;
        Maxi += A[i].second;
    }

    if(Mini <= 0 && Maxi >= 0){
        cout << "Yes" << endl;

        ll diff = Mini;
        for(int i = 0; i < N; i++){
            ll d = A[i].second - A[i].first;
            // cout  << "d : "<< diff << " " << d << endl;

            if(diff + d <= 0){
                cout << A[i].second << " "; // X[i]
                diff += d;
            }else{
                cout << A[i].first - diff << " ";
                diff = 0;
            }
        }

    }else{
        cout << "No" << endl;
    }
    return 0;
}