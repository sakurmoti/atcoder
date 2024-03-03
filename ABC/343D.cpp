#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,T; cin >> N >> T;
    
    int ans = 1; // all zero
    multiset<ll> board;
    for(int i = 0; i < N; i++) board.insert(0);

    vector<ll> score(N+1, 0);
    for(int i = 0; i < T; i++){
        ll A,B; cin >> A >> B;

        ll now = score[A];
        board.erase(board.find(now));    
        if(!board.contains(now)) ans--;

        ll next = now + B;
        if(!board.contains(next)){
            ans++;
        }
        board.insert(next);
        score[A] = next;

        cout << ans << endl;
    }


    return 0;
}