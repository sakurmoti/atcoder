#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,Q; cin >> N >> Q;
    string S; cin >> S;
    S.insert(S.begin(), ' ');

    // 0からiまで見たときの隣り合う文字の個数
    vector<int> culsum(N+1, 0);
    for(int i = 1; i < N; i++){
        culsum[i+1] = culsum[i];
        if(S[i] == S[i+1]){
            culsum[i+1]++;
        }
    }

    for(int q = 0; q < Q; q++){
        int l,r; cin >> l >> r;

        // printf("culsum[l] = %d\n", culsum[l]);
        // printf("culsum[r] = %d\n", culsum[r]);
        cout << culsum[r] - culsum[l] << endl;
    }
    return 0;
}