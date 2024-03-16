#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int T; cin >> T;

    while(T--){
        int N,A,B;
        cin >> N >> A >> B;

        // ルークはポーンで置けない行に置くのが最適
        // N が奇数なら {N/2 + 1} * (N-A)個ポーンが置ける
        // N が偶数なら {N/2} * (N-A)

        if((N-A) >= 0 && min((N-A), ((N+1)/2)) * (N-A) >= B){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}