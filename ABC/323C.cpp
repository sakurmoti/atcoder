#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M; cin >> N >> M;
    vector<pair<int, int>> A(M);
    for(int i = 0; i < M; i++){
        int a; cin >> a;
        A[i] = make_pair(a, i);
    }

    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    vector<ll> score(N, 0);
    for(int i = 0; i < N; i++){
        score[i] = i+1;
        for(int j = 0; j < M; j++){
            if(S[i][j] == 'o') score[i] += A[j].first;
        }
    }

    ll MAX = *max_element(score.begin(), score.end());
    sort(A.rbegin(), A.rend());    

    for(int i = 0; i < N; i++){
        int ans = 0;
        for(int j = 0; j < M; j++){
            if(score[i] >= MAX) break;
            int prev = A[j].second;

            if(S[i][prev] == 'x'){
                score[i] += A[j].first;
                ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}