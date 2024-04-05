#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,K; cin >> N >> K;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    for(int i = 0; i < N; i++){
        if(A[i] % K == 0){
            cout << A[i] / K << " ";
        }
    }

    cout << endl;
    return 0;
}