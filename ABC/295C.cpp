#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &x : A) cin >> x;

    int ans = 0;
    set<int> cnt;
    for(auto x : A){
        if(cnt.count(x)){
            ans++;
            cnt.erase(x);

        }else{
            cnt.insert(x);

        }
    }
    cout << ans << endl;
    
    return 0;
}