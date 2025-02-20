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
    int N; cin >> N;
    vector<ll> A(N),B(N-1);
    for(auto &_v : A) cin >> _v;
    for(auto &_v : B) cin >> _v;

    // A[i]を1つ消す操作に該当する
    // A[i]を消した時、全てBに入れられるか
    sort(ALL(A));
    sort(ALL(B));

    auto check = [&](int idx){
        bool ret = true;
        int j = 0;
        for(int i = 0; i < N; i++){
            if(i == idx) continue;
            if(A[i] > B[j]){
                ret = false;
            }
            j++;
        }
        return ret;
    };

    // A[0]を消してできるか
    bool f0 = check(0);

    // A[N-1]でできるか
    bool fN = check(N-1);

    if(f0 == true){
        cerr << "case1 : ";
        cout << A[0] << endl;
    
    }else if(fN == false){
        cerr << "case2 : ";
        cout << -1 << endl;
    
    }else{
        int ok = N-1; // N-1ではできて
        int ng = -1; // 0ではできない

        while(abs(ok-ng) >= 2){
            int mid = (ok+ng)/2;
            bool f = check(mid);

            if(f){
                ok = mid;
            }else{
                ng = mid;
            }
        }

        cerr << "case 3 : ";
        cout << A[ok] << endl;
    }
    return 0;
}