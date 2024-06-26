#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll Sx,Sy,Tx,Ty;
    cin >> Sx >> Sy >> Tx >> Ty;

    if((Sx+Sy)%2 == 0 && Sx < Tx){
        Sx++;
    }else if((Sx+Sy)%2 == 1 && Sx > Tx){
        Sx--;
    }

    if((Tx+Ty)%2 == 0 && Tx < Sx){
        Tx++;
    }else if((Tx+Ty)%2 == 1 && Tx > Sx){
        Tx--;
    }

    // printf("%lld %lld : %lld %lld\n",Sx,Sy,Tx,Ty);

    ll disX = abs(Sx-Tx);
    ll disY = abs(Sy-Ty);
    // cout << disX << " " << disY << endl;
    cout << disY + max(0LL, (disX-disY)/2 + (disX-disY)%2);
    return 0;
}