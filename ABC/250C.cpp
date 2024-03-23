#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,Q; cin >> N >> Q;
    vector<int> A(N+1, 0);
    vector<int> index(N+1, 0); //index[i] := A[index[i]] = iなるidx
    iota(ALL(A), 0);
    iota(ALL(index), 0);

    while(Q--){
        int x; cin >> x;

        if(index[x] != N){
            swap(A[index[x]], A[index[x] + 1]);
            swap(index[A[index[x]]], index[A[index[x] + 1]]);


        }else{
            swap(A[index[x]], A[index[x] - 1]);
            swap(index[A[index[x]]], index[A[index[x] - 1]]);

        }

        // for(auto &_v : A) cout << _v << " "; cout << endl;
        // for(auto &_v : index) cout << _v << " "; cout << endl;
    }

    for(int i = 1; i <= N; i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}