#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    
    map<int, int> dict;
    for(int i = 0; i < N; i++){
        int a,c; cin >> a >> c;
        
        if(!dict.contains(c)){
            dict[c] = a;

        }else if(dict[c] > a){
            dict[c] = a;

        }
    }

    int ans = 0;
    for(auto [k,v] : dict){
        ans = max(ans, v);
    }

    cout << ans << endl;
    return 0;
}