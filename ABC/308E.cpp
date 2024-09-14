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
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;
    string S; cin >> S;

    vector<vector<ll>> csum(10, vector<ll>(N+1, 0));
    auto update = [&](int i, int j){
        csum[j][i+1] += (A[i] == (j%3));
    };
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 9; j++){
            csum[j][i+1] = csum[j][i];
        }

        if(S[i] == 'M'){
            update(i,0);
            update(i,1);
            update(i,2);

        }else if(S[i] == 'E'){
            update(i,3);
            update(i,4);
            update(i,5);

        }else{
            update(i,6);
            update(i,7);
            update(i,8);
        }
    }
    
    // for(int j = 0; j < 9; j++){
    //     if(j/3==0){
    //         cout << "M, ";
    //     }else if(j/3==1){
    //         cout << "E, ";
    //     }else{
    //         cout << "X, ";
    //     }

    //     if(j%3==0){
    //             cout << "0 : ";
    //         }else if(j%3==1){
    //             cout << "1 : ";
    //         }else{
    //             cout << "2 : ";    
    //         }
    //     for(int i = 0; i <= N; i++){
    //         cout << csum[j][i] << " ";
    //     }cout << "\n\n";
    // }

    auto mex = [](int a, int b, int c){
        if(a!=0 && b!=0 && c!=0) return 0;
        if(a!=1 && b!=1 && c!=1) return 1;
        if(a!=2 && b!=2 && c!=2) return 2;
        return 3;
    };

    ll ans = 0;
    for(int i = 1; i < N; i++){
        if(S[i-1] != 'E') continue;

        int k2 = A[i-1];
        for(int k1 = 0; k1 < 3; k1++){
            for(int k3 = 6; k3 < 9; k3++){
                ll m = csum[k1][i] - csum[k1][0];
                ll x = csum[k3][N] - csum[k3][i];

                ans += mex(k1, k2, k3%3) * (m*x);
                // printf("i=%d, k1=%d, k2=%d, k3=%d, : = %d * %d\n",i,k1,k2,k3%3, mex(k1, k2, k3%3), (m*x));
            }
        }
    }

    cout << ans << endl;
    return 0;
}