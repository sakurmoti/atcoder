#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> A(N),B(N),C(N),D(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];
    for(int i = 0; i < N; i++) cin >> D[i];

    //半分全列挙
    //AB、CDで分ける
    vector<int> P;
    vector<int> Q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            P.push_back( A.at(i) + B.at(j) );
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            Q.push_back( C.at(i) + D.at(j) );
        }
    }

    //このときP+Q=Kとなる組(P,Q)が存在すれば、何かしらの組(A,B,C,D)が存在するということ
    //P,Qをソートして二分探索でP = K-Qとなる組が存在するか確認する
    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());
    
    for(int i = 0; i < P.size(); i++){
        int ok = Q.size()-1;
        int ng = 0;
        int mid = (ok+ng)/2;

        while(abs(ok-ng) > 1){
            if(P.at(i) + Q.at(mid) >= K){
                ok = mid;
            
            }else{
                ng = mid;

            }

            //printf("P=%d, Q=%d, K=%d\n", P[i],Q[ok],K);
            mid = (ok+ng)/2;
        }

        if(P.at(i) + Q.at(ok) == K){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}