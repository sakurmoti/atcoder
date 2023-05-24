#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N+1);
    for(int i = 1; i <= N; i++) cin >> A[i];

    //1号室から左に累積最大値を見る
    vector<int> P(N+10,0);
    for(int i = 0; i < N; i++){
        P.at(i+1) = max(A.at(i+1), P.at(i));
    }

    //N号室から順に右に累積最大値
    vector<int> Q(N+10,0);
    for(int i = N; i >= 0; i--){
        Q.at(i) = max(A.at(i), Q.at(i+1));
    }

    int D;
    cin >> D;

    int L,R;
    for(int i = 0; i < D; i++){
        cin >> L >> R;

        //1号室からL-1号室の最大値
        int leftMax = P.at(L-1);

        //R+1号室からN号室までの最大値
        int rightMax = Q.at(R+1);

        cout << max(leftMax, rightMax) << endl;

    }
    return 0;
}