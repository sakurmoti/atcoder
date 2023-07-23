#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &v : A) cin >> v;
    
    map<int, int> ball;
    for(int i = 0; i < N; i++){
        ball[A[i]]++;
    }

    //全てのballに対してnC2の組合せ数をカウントする
    ll comb = 0;
    set<int> counted;
    for(int i = 0; i < N; i++){
        if(counted.find(A[i]) != counted.end()) continue;
        counted.insert(A[i]);

        ll n = ball[A[i]];
        //nC2
        comb += n*(n-1)/2;
    }
    // printf("comb = %lld\n", comb);

    for(int i = 0; i < N; i++){
        ll ans = comb;
        ans -= (ball[A[i]] -1); //banするボールを含む組合せはballの個数-1個
        cout << ans << endl;
    }

    return 0;
}