#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> A(N); for(auto &_v : A) cin >> _v;

    deque<int> B;
    for(int i = 0; i < N; i++){
        if(i%2 == 0){
            B.push_back(A[i]);
        }else{
            B.push_front(A[i]);
        }
    }

    if(N%2 == 0){
        for(int i = 0; i < N; i++){
            cout << B[i] << " ";
        }
    }else{
        for(int i = N-1; i >= 0; i--){
            cout << B[i] << " ";
        }
    }
    return 0;
}