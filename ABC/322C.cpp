#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M; cin >> N >> M;
    vector<int> A(M);
    for(auto &_v : A) cin >> _v;
    
    for(int i = 1; i <= N; i++){
        int next = *lower_bound(A.begin(), A.end(), i);
        cout << next - i << endl;
    }
    return 0;
}