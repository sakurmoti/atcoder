#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    vector<int> A(110);
    int N = 0;
    for(int i = 0; i < 110; i++){
        cin >> A[i];
        if(A[i] == 0){
            N = i;
            break;
        }
    }

    for(int i = N; i >= 0; i--){
        cout << A[i] << endl;
    }

    
    return 0;
}