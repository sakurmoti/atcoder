#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> a(N);
    for(auto &_v : a) cin >> _v;

    for(int i = 0; i < N-1; i++){
        if(a[i] != a[i+1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}