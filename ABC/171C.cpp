#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;

    /*26進数とみなせばよい。0-idxにするためNから1引く*/
    N -= 1;

    string ans;
    while(N >= 0){
        char c = 'a' + N%26;
        N/=26;
        N-=1;

        ans += c;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}