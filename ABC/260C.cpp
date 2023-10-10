#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N,X,Y;
ll convert(int n, char c){
    if(c == 'R'){
        if(n==1) return 0;

        return convert(n-1, 'R') + X*convert(n, 'B');
    }else{
        if(n==1) return 1;

        return convert(n-1, 'R') + Y*convert(n-1, 'B');
    }
}

int main(){
    cin >> N >> X >> Y;
    cout << convert(N, 'R') << endl;
    return 0;
}