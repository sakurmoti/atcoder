#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    map<int, long long> cnt;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        a %= 100;

        cnt[a]++;
    }

    long long ans = 0;
    for(int i = 1; i < 50; i++){
        ans += cnt[i]*cnt[100-i];
    }

    //nC2
    ans += (cnt[50])*(cnt[50]-1) / 2;
    ans += (cnt[0])*(cnt[0]-1) / 2;
    cout << ans << endl;
    return 0;
}