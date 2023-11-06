#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int X,Y; cin >> X >> Y;

    if(-2 <= X-Y && X-Y <= 3){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}