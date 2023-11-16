#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> P(N+1);
    for(int i = 1; i <= N; i++){
        cin >> P[i];
    }

    // k個選ぶのを固定したとき、選べるのは分子のみ
    // dp[i][j] := i番目のコンテストまで見たとき、j個選んだ時の分子の最大値
    vector<vector<double>> dp(N+1, vector<double>(N+1, 0.0));
    dp[1][1] = P[1];
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= i; j++){
            // max(i個目のコンテストを選ぶとき, 選ばないとき)
            dp[i][j] = max(0.9 * dp[i-1][j-1] + P[i], dp[i-1][j]);
        }
    }
    
    double Rmax = -1e20;
    for(int k = 1; k <= N; k++){
        double bunbo = 0.0;
        for(int i = 1; i <= k; i++){
            bunbo += pow(0.9, k-i);
        }
        double R = dp[N][k]/bunbo - ( 1200.0/sqrt(k) );

        Rmax = max(Rmax, R);
    }

    cout << fixed << setprecision(10) << Rmax << endl;

    return 0;
}