#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int L,R; cin >> L >> R;
    string S; cin >> S;

    int N = S.size();
    for(int i = 0; i < N; i++){
        if(L-1 <= i && i <= R-1){
            cout << S[(R-1)+(L-1)-i];
        }else{
            cout << S[i];
        }
    }
    cout << endl;
    return 0;
}