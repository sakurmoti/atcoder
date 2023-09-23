#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,X;
    cin >> N >> X;
    vector<int> A(N-1);
    for(auto &_v : A) cin >> _v;

    for(int i = 0; i <= 100; i++){
        vector<int> B = A;
        B.push_back(i);

        sort(B.begin(), B.end());

        ll sum = 0;
        for(int i = 1; i < B.size()-1; i++){
            sum += B[i];
        }

        if(sum >= X){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}