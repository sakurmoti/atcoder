#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    cin >> N;

    vector<int> A(N+1);
    for(int i = 1; i <= N; i++) cin >> A[i];

    set<int> num;
    for(int i = 1; i <= N; i++){
        if(!num.count(i)){
            num.insert(A[i]);
        }
    }

    vector<int> ans;
    for(int i = 1; i <= N; i++){
        if(!num.count(i)){
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";

    return 0;
}