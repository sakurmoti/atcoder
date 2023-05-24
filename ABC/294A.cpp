#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    cin >> N;

    vector<int> ans;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;

        if(x%2 == 0){
            ans.push_back(x);
        }
    }

    for(auto x : ans) cout << x << " ";
    
    return 0;
}