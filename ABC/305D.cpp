#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    vector<int> sum(N,0);
    for(int i = 1; 2*i+1 <= N; i++){
        sum[i] = sum[i-1] + (A[2*i]- A[2*i-1]);
        // cout << sum[i] << endl;
    }

    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int l,r;
        cin >> l >> r;

        //lのidxを見つける
        auto itrL = lower_bound(A.begin(), A.end(), l);
        int l_idx = distance(A.begin(), itrL);

        //r_idx
        auto itrR = lower_bound(A.begin(), A.end(), r);
        int r_idx = distance(A.begin(), itrR);
        // printf("l_idx = %d, r_idx = %d\n",l_idx, r_idx);

        int all = sum.at(r_idx/2) - sum.at(l_idx/2);
        int noSleepR = (A[r_idx] - r);
        int addSleepL = (A[l_idx] - l);
        // printf("noSR=%d-%d, addSL=%d-%d\n",A[r_idx],r,A[l_idx],l);

        // printf("all=%d, noL=%d, noR=%d\n",all,noSleepL,noSleepR);
        if(r_idx % 2 == 0) all -= noSleepR;
        if(l_idx % 2 == 0) all += addSleepL;
        cout << all << endl;
    }
    return 0;
}