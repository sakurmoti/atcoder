#include <bits/stdc++.h>
using namespace std;

int main(){
    string buf = "atcoder";
    int L,R;
    cin >> L >> R;

    cout << buf.substr(L-1,R-L+1) << endl;
    return 0;
}