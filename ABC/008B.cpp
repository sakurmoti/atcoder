#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    map<string, int> dict;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        dict[s]++;
    }

    int M = -1;
    string ans;
    for(auto v : dict){
        if(M < v.second){
            M = v.second;
            ans = v.first;
        }
    }
    cout << ans << endl;
    return 0;
}