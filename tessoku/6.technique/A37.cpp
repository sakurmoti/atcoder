#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,M,B;
    cin >> N >> M >> B;
    
    long long sumA = 0;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        sumA += a;
    }

    long long sumC = 0;
    for(int i = 0; i < M; i++){
        int c;
        cin >> c;
        sumC += c;
    }

    long long ans = M*sumA + (N*M)*B + N*sumC;
    cout << ans << endl;
    return 0;
}