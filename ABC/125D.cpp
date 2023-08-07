#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    //操作を行ったとき、負の数は2個減るか、1個増えて1個減るだから数は変わらない
    //つまり偶数なら全て消すことができ、奇数なら絶対値の最小値を負にすればよい
    int minus=0;
    int minimum = 1e9;
    ll sum = 0;
    for(int i = 1; i <= N; i++){
        sum += abs(A[i]);

        if(A[i] < 0){
            minus++;
        }

        minimum = min(minimum, abs(A[i]));
    }

    if(minus%2==0){
        cout << sum << endl;
    }else{
        cout << sum - 2*abs(minimum) << endl;
    }
    return 0;
}