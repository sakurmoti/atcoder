#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> A,B;    

long long solve(bool omote, bool ura){
    long long x = 0;
    long long y = 0;
    for(int i = 0; i < N; i++){
        long long a,b;
        if(omote) a = A[i];
        else a = -A[i];

        if(ura) b = B[i];
        else b = -B[i];

        if(a+b > 0){
            x += A[i];
            y += B[i];
        }
    }
    return abs(x) + abs(y);
}

int main(){
    cin >> N;

    A.resize(N);
    B.resize(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }

    //表が負に最大(最小), 正に最大、裏が最小と最大のパターンがある
    //この4パターンを探索する
    long long ans = -1;
    ans = max({solve(true, true), solve(true, false), solve(false, true), solve(false, false)});
    cout << ans << endl;

    return 0;
}