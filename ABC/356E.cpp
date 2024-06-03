#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()

#pragma GCC optimize("O4")

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;
    sort(ALL(A));

    ll sum = 0;
    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            int div = A[j] / A[i];
            sum += div;
        }
    }

    cout << sum << endl;
    return 0;
}