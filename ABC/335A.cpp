#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    int N = S.size();
    S[N-1] = '4';
    cout << S << endl;
    return 0;
}