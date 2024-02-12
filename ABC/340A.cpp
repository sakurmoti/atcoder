#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    
    int n = A;
    while(n != B){
        cout << n << " ";
        n += C;
    }
    cout << n << endl;
    return 0;
}