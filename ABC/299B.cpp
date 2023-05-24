#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,T;
    cin >> N >> T;
    
    vector<int> C(N),R(N);
    for(auto &x : C) cin >> x;
    for(auto &x : R) cin >> x;

    vector<pair<int, int>> buf;
    for(int i = 0; i < N; i++){
        if(C[i] == T){
            buf.emplace_back(R[i],i+1);
        }
    }
    
    if(!buf.empty()){
        sort(buf.begin(), buf.end());
        cout << buf.back().second << endl;
    
    }else{
        for(int i = 0; i < N; i++){
            if(C[i] == C[0]){
                buf.emplace_back(R[i],i+1);
            }
        }
        sort(buf.begin(), buf.end());
        cout << buf.back().second << endl;
        
    }
    return 0;
}
