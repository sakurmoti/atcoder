#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,M; cin >> N >> M;
    vector<int> A(M+1, -1);
    for(int i = 1; i <= M; i++){
        cin >> A[i];
    }

    pair<int, int> ans = make_pair(A[1], 1);
    vector<int> sum(N+1, 0);
    for(int i = 1; i <= M; i++){
        sum[A[i]]++;

        if(ans.second < sum[A[i]]){
            ans = make_pair(A[i], sum[A[i]]);
        }else if(ans.second == sum[A[i]] && ans.first >= A[i]){
            ans = make_pair(A[i], sum[A[i]]);
        }

        // printf("num: %d, cnt: %d\n", ans.first, ans.second);
        cout << ans.first << endl;
    }
    return 0;
}