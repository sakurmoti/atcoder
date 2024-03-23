#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    for(int i = 0; i < N-1; i++){
        cout << A[i] * A[i+1] << " \n"[i == N-2];
    }
    return 0;
}