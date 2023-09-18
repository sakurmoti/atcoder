#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    string s[] = {"a","b","c"};
    for(int i = 0; i < pow(3,N); i++){
        int buf = i;
        string ans = "";
        for(int j = 0; j < N; j++){
            ans += s[buf%3];
            buf/=3;
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}