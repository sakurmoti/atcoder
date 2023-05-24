#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &v : A) cin >> v;


    for(int i = 0; i < N-1; i++){
        if(A[i] < A[i+1]){
            while(A[i] != A[i+1]){
                cout << A[i] << " ";
                A[i]++;
            }

        }else{
            while(A[i] != A[i+1]){
                cout << A[i] << " ";
                A[i]--;
            }

        }
    }

    cout << A[N-1] << endl;
    return 0;
}