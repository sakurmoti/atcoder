#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i].second >> A[i].first;
    }

    sort(A.begin(), A.end());

    ll t = 0;
    for(int i = 0; i < N; i++){
        t += A[i].second;
        if(t > A[i].first){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}