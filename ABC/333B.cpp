#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S,T;
    cin >> S >> T;

    sort(ALL(S));
    sort(ALL(T));

    set<string> d1 = {"AB", "BC", "CD", "DE", "AE"};
    set<string> d2 = {"AC", "AD", "BD", "BE", "CE"};


    if( (d1.count(S) && d1.count(T)) || (d2.count(S) && d2.count(T)) ) cout << "Yes";
    else cout << "No";

    cout << endl;
    return 0;
}