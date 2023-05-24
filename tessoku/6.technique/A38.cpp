#include <bits/stdc++.h>
using namespace std;

int main(){
    int D,N;
    cin >> D >> N;

    vector<int> day(D+1, 24);
    day[0] = 0;
    int L,R,H;
    for(int i = 0; i < N; i++){
        cin >> L >> R >> H;

        for(int j = L; j <= R; j++){
            day.at(j) = min(day.at(j), H);
        }
    }

    long long ans = 0;
    for(auto v : day) ans += v;
    cout << ans << endl;
    return 0;
}