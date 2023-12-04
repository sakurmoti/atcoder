#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,M,L; cin >> N >> M >> L;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i].first;
        A[i].second = i;
    }

    vector<pair<int, int>> B(M);
    for(int i = 0; i < M; i++){
        cin >> B[i].first;
        B[i].second = i;
    }

    sort(RALL(A));
    sort(RALL(B));

    set<pair<int, int>> noGood;
    for(int i = 0; i < L; i++){
        int c,d; cin >> c >> d;
        noGood.insert(make_pair(c-1,d-1));
    }

    int ans = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(noGood.find(make_pair(A[i].second, B[j].second)) == noGood.end()){
                ans = max(ans, A[i].first + B[j].first);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}