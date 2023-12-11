#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,M; cin >> N >> M;
    string S; cin >> S;

    int shirts = 0, kyopro = 0;
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(S[i] != '0'){
            shirts++;
        }

        if(S[i] == '2'){
            kyopro++;
        }

        if(S[i] == '0'){
            if(ans < kyopro) ans = kyopro;
            if(M + ans < shirts) ans = shirts - M;

            kyopro = 0;
            shirts = 0;
        }
    }

    if(ans < kyopro) ans = kyopro;
    if(M + ans < shirts) ans = shirts - M;
    
    cout << ans << endl;
    return 0;
}