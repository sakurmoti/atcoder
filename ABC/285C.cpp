#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    //1,2,3 ... 26の次が11
    long long ans=0;
    long long pre = 1;
    for(int i = S.size()-1; i >= 0; i--){
        char c = S.at(i);
        ans += ((int)c - 'A'+1) * pre;

        pre *= 26;
    }

    cout << ans << endl;
    return 0;
}