#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for(auto &_v : A) for(auto &_vv : _v) cin >> _vv;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i][j] == 1) cout << j+1 << " ";
        }
        cout << endl;
    }
    return 0;
}