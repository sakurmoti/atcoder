#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,K;
    cin >> N >> K;

    vector<double> dice(N+1, (1.0/N));
    double ans = 0;
    for(int i = 1; i <= N; i++){
        int d = i;
        while(d < K){
            d*=2;
            dice[i] /= 2.0;
        }
        ans += dice[i];
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}