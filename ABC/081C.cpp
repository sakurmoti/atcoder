#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,K;
    cin >> N >> K;
    
    map<int,int> ball;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        ball[a]++;
    }

    vector<int> cnt(N+1);
    for(int i = 0; i <= N; i++){
        cnt[i] = ball[i];
    }

    sort(cnt.begin(), cnt.end());

    int c = (int)ball.size() - K;
    
    int ans = 0;
    for(int i = 0; i < c; i++){
        ans += cnt[i];
    }

    cout << ans << endl;
    return 0;
}