#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,L; cin >> N >> L;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;


    int ans=0;
    for(int i = 0; i < N; i++){
        if(L <= A[i]){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}