#include <bits/stdc++.h>
using namespace std;

//n個から3個選ぶ組合せ数
long long nC3(long long N){
    return N*(N-1)*(N-2)/6;
}

int main(){
    int N;
    cin >> N;

    map<int, int> cnt;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;

        cnt[a]++;
    }

    long long ans = 0;
    for(auto itr = cnt.begin(); itr != cnt.end(); itr++){
        ans += nC3(itr->second);
    }

    cout << ans << endl;

    return 0;
}