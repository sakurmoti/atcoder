#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> A(N);
    for(auto &x : A) cin >> x;
    vector<int> B(M);
    for(auto &x : B) cin >> x;

    vector<int> C;
    C = A;
    C.insert(C.end(), B.begin(), B.end());
    sort(C.begin(), C.end());

    for(int i = 0; i < N; i++){
        int ng = N+M;
        int ok = 0;
        while(abs(ok-ng) >= 2){
            int mid = (ok+ng)/2;
            if(A.at(i) < C.at(mid)) ng = mid;
            else ok = mid;
        }

        ok++; //1-idx
        cout << ok << " \n"[i==N-1];
    }
    
    for(int i = 0; i < M; i++){
        int ng = N+M;
        int ok = 0;
        while(abs(ok-ng) >= 2){
            int mid = (ok+ng)/2;
            if(B.at(i) < C.at(mid)) ng = mid;
            else ok = mid;
        }

        ok++; //1-idx
        cout << ok << " \n"[i==N-1];
    }
    return 0;
}