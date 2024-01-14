#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S,T; cin >> S >> T;
    int N = S.size();

    map<char, char> used;
    for(int i = 0; i < N; i++){
        char c = S[i];
        if(used[c]){
            
        }

        if(S[i] != T[i]){
            // S[i]をT[i]に変更
            used[S[i]] = true;
        }
    }


    return 0;
}