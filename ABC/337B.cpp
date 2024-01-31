#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    bool ans = true;

    int N = S.size();
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(i < j && S[i] > S[j]){
                ans = false;
            }
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}