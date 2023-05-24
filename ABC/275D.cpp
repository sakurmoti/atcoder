#include <bits/stdc++.h>
using namespace std;

//メモ化再帰
map<long long, long long> memo;
long long f(long long x){
    if(memo.count(x)) return memo[x];
    else return memo[x] = f(x/2) + f(x/3);
}

int main(){
    long long N;
    cin >> N;

    memo[0] = 1;

    cout << f(N) << endl;
    return 0;
}