#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> A(N);
    for(auto &x : A) cin >> x;

    sort(A.begin(), A.end());
    unique(A.begin(), A.end());
    //for(auto x : A) cout << x << " ";

    //要するにどれだけ連続しているかということ
    int m = 0;

    for(int i = 0; i < K; i++){
        if(A[i] == i){
            m++;
        
        }else{
            break;
        
        }
    }

    cout << m << endl;
    return 0;
}