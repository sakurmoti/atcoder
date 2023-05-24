#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;

    set<long long> temp;
    for(long long a = 2; a*a <= N; a++){
        long long x = a*a; //b=2
        //cout << "-------" << a << "---------" << endl;
        while(x <= N){
            //cout << x << endl;
            temp.insert(x);
            x *= a; //bを一つずつ増やす
        }
    }

    cout << N-temp.size()<< endl;

    return 0;
}