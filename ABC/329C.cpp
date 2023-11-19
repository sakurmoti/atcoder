#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    string S; cin >> S;

    map<char, int> dict;
    dict[S[0]]++;
    int cnt = 1;
    for(int i = 1; i < N; i++){
        char c = S[i];
        char prev = S[i-1];

        if(c==prev){
            cnt++;
            dict[c] = max(dict[c], cnt);
        }else{
            dict[prev] = max(dict[prev], cnt);
            cnt = 1;
        }
    }

    int ans = 0;
    for(auto v : dict){
        // cout << v.first << " : " << v.second << endl;
        ans += v.second;
    }
    cout << ans << endl;
    return 0;
}