#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,L; cin >> N >> L;
    int K; cin >> K;

    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    // 答えの上界はL, 下界は0になるのでにぶたんできる
    // O(N log_L)
    int l = 0;
    int r = L;
    while(abs(r-l) > 1){
        // fprintf(stderr, "l=%d, r=%d\n", l, r);
        int d = (r+l)/2;

        int k = 0;
        int now = 0;
        for(int i = 0; i <= N; i++){
            // fprintf(stderr, "now=%d\n", now);
            if(A[i] - now >= d && k < K){
                // fprintf(stderr, "%d ", i);
                now = A[i];
                k++;
            }
        }
        if(L - now < d){
            r = d;
            continue;
        }

        if(k < K){
            r = d;
        }else{
            l = d;
        }
    }

    cout << l << endl;
    return 0;
}