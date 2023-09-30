#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,X; cin >> N >> X;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;
    
    bitset<22> bits(X);
    int sum = 0;
    for(int i = 0; i < N; i++){
        if(bits.test(i)){
            sum += A[i];
        }
    }
    cout << sum << endl;
    return 0;
}