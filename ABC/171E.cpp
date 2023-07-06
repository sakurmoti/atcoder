#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    const int BIT = 30; //2^30 > 10^9
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &v : A) cin >> v;

    vector<int> x(N);
    /*
    A1 =      x2 ^ x3 ^ x4
    A2 = x1 ^      x3 ^ x4
    A3 = x1 ^ x2 ^      x4
    A4 = x1 ^ x2 ^ x3
    -------------------------
    B = A1^A2^A3^A4 = x1 ^ x2 ^ x3 ^ x4
    (同じ数のXOR演算は偶数なら0、奇数ならそのもの a^a = 0, a^a^a = a)
    */
    
    int B = 0;
    for(int i = 0; i < N; i++){
        B ^= A[i];
    }

    /*
    B  = x1 ^ x2 ^ x3 ^ x4
    A1 =      x2 ^ x3 ^ x4
    -----------------------
    B ^ A1 = x1  (x2^x2=0 により消えた)
    これからx1を求める
    */
    
    for(int i = 0; i < N; i++){
        x[i] = B ^ A[i];
    }

    for(auto &v : x) cout << v << ' ';
    return 0;
}