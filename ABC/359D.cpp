#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main(){
    int N,K; cin >> N >> K;
    string S; cin >> S;
    S.insert(S.begin(), ' ');
    
    /*
    dp[T][P] := Tに含まれる?をA,Bに変えた文字列のうち、
        ・良い文字列
        ・末尾min(K-1, |T|)文字がPと等しい
    を満たす組合せの個数
    */
    
    
    return 0;
}