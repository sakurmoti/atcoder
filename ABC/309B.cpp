#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<vector<char>> A(N, vector<char>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i==0){
                if(j==0) cout << A[i+1][j];
                else cout << A[i][j-1];

            }else if(i==N-1){
                if(j==N-1) cout << A[i-1][j];
                else cout << A[i][j+1];
            
            }else if(j==0){
                cout << A[i+1][j];
            }else if(j==N-1){
                cout << A[i-1][j];
            }else{
                cout << A[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}