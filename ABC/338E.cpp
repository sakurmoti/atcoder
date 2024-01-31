#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> A(N),B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    
    bool isParallel = false;
    set<int> s1;
    for(int i = 0; i < N; i++){
        s1.insert(A[i] + B[i]);
    }
    if(s1.size() == 1) isParallel = true;

    set<int> s2;
    for(int i = 0; i < N; i++){
        if(A[i] == 0) A[i] = 2*N;
        if(B[i] == 0) B[i] = 2*N;
    }
    for(int i = 0; i < N; i++){
        s2.insert(A[i] + B[i]);
    }
    if(s2.size() == 1) isParallel = true;


    if(isParallel) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}