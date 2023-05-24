#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    int a,b;
    set<int> ans;
    for(int i = 0; i < N; i++){
        cin >> a;
        ans.insert(a);
    }

    for(int i = 0; i < M; i++){
        cin >> b;
        
        if(ans.count(b)){
            ans.erase(b);
        
        }else{
            ans.insert(b);
        
        }
    }

    for(int c : ans){
        cout << c << " ";
    }
    return 0;
}