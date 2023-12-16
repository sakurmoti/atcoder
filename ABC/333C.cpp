#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;

    vector<ll> repunit = {
        1,
        11,
        111,
        1111,
        11111,
        111111,
        1111111,
        11111111,
        111111111,
        1111111111,
        11111111111,
        111111111111,
    };

    vector<ll> sum;
    int M = repunit.size();
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < M; k++){
                sum.push_back(repunit[i] + repunit[j] + repunit[k]);
            }
        }
    }

    sort(ALL(sum));
    sum.erase(unique(ALL(sum)), sum.end());

    cout << sum[N-1] << endl;
    return 0;
}