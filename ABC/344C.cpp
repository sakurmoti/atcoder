#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;
    int M; cin >> M;
    vector<int> B(M);
    for(auto &_v : B) cin >> _v;
    int L; cin >> L;
    vector<int> C(L);
    for(auto &_v : C) cin >> _v;

    set<int> st;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < L; k++){
                st.insert(A[i] + B[j] + C[k]);
            }
        }
    }

    int Q; cin >> Q;
    while(Q--){
        int X; cin >> X;

        if(st.contains(X)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}