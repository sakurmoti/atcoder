#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> a(M);
    for(int i = 0; i < M; i++) cin >> a[i];

    dsu d(N+10);
    for(int i = 0; i < M; i++){
        d.merge(a[i], a[i]+1);
    }

    int st=-1;
    for(int i = 1; i <= N; i++){
        if(d.same(i, i+1)){
            if(st < 0) st = i;
        
        }else{
            if(st > 0){
                for(int j = i; j >= st; j--){
                    cout << j << " ";
                }
                st=-1;
            
            }else{
                cout << i << " ";
            }
        }
    }

    return 0;
}