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
    int N; cin >> N;
    vector<ll> H(N);
    for(auto &_v : H) cin >> _v;
    
    ll T = 0;
    for(int i = 0; i < N; i++){
        while(T%3 != 0 && H[i] > 0){
            T++;
            if(T%3==0) H[i] -= 3;
            else H[i]--;

            // printf("A : turn=%lld hp=%lld\n",T, H[i]);
        }

        // 3ターンで5削れる
        T += 3*(H[i]/5);
        H[i] %= 5;

        // printf("B : turn=%lld hp=%lld\n",T, H[i]);

        while(H[i] > 0){
            T++;
            if(T%3==0){
                H[i]-=3;
            }else{
                H[i]--;
            }
            // printf("C : turn=%lld hp=%lld\n",T, H[i]);
        }

        // printf("\n\n");
    }

    cout << T << endl;
    return 0;
}