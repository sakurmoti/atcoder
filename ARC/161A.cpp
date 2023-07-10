#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> A(N+1,-1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    if(N==1){
        cout << "Yes" << endl;
        return 0;
    }

    //S[i-1] < S[i] > S[i+1] (i:=2k+1)となればよい
    //自由に並び替えて良いのでソート
    sort(A.begin(), A.end());

    bool ans = true;
    vector<int> B(N+1,1e9);
    for(int i = 1; i <= (N+1)/2; i++){
        B.at(2*i-1) = A.at(i);
    }
    for(int i = 1; i <= (N-1)/2; i++){
        B.at(2*i) = A.at(i + (N+1)/2);
    }

    // for(auto &v : B) cout << v << ' ';
    for(int i = 2; i <= N; i+=2){
        if(! (B.at(i-1) < B.at(i) && B.at(i) > B.at(i+1))) {
            ans = false;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}