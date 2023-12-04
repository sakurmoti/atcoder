#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int K; cin >> K;

    // A[i] = 10*A[i-1] + 7
    // Aのmod Kが重複したらその後はループする
    // そのためO(K)で解ける
    
    int prev = 0;
    vector<bool> memo(K, false);
    for(int i = 1; i <= 1e6; i++){
        int A = 10*prev + 7;
        A %= K;

        if(A == 0){
            cout << i << endl;
            return 0;
        
        }else if(memo[A]){
            break;
        }else{
            memo[A] = true;
        }

        prev = A;
    }

    cout << -1 << endl;
    return 0;
}