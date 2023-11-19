#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,M; cin >> N >> M;
    string S,T; cin >> S >> T;

    // Sは少なくとも1つTを含む
    // Sの中のTの前後はTのsubstrであればよい

    vector<string> subT;
    for(int i = 0; i < M; i++){
        for(int j = 1; j <= M-i; j++){
            string subst = T.substr(i, j);
            subT.push_back(subst);
        }
    }

    bool isContainsT = false;
    vector<bool> checked(N, false);
    vector<int> R,L;
    for(int i = 0; i < N; i++){
        string subS = S.substr(i, M);
        if(subS == T){
            isContainsT = true;
            R.push_back(i-1);
            L.push_back(i+M);
        }
    }

    if(!isContainsT){
        cout << "No" << endl;
        return 0;
    }

    for(auto &_v : R) cout << _v << ' ';
    cout << endl;
    for(auto &_v : L) cout << _v << ' ';
    return 0;
}