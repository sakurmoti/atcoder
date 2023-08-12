#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(auto &v : A) cin >> v;
    for(auto &v : B) cin >> v;

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    int sum=0;
    for(int i = 0; i < N; i++){
        sum += A[i]*B[i];
    }
    cout << sum << endl;
    return 0;
}