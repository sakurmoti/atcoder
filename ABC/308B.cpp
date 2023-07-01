#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;

    vector<string> C(N+1), D(M+1);
    for(int i = 1; i <= N; i++){
        cin >> C[i];
    }
    for(int i = 1; i <= M; i++){
        cin >> D[i];
    }
    vector<int> P(M+1);
    for(auto &v : P) cin >> v;

    ll sum = 0;
    for(int i = 1; i <= N; i++){
        bool isFind = false;
        for(int j = 1; j <= M; j++){
            if(C[i] == D[j]){
                sum += P[j];
                isFind = true;
                break;
            }
        }

        if(!isFind) sum += P[0];
        // cout << sum << endl;
    }

    cout << sum << endl;


    return 0;
}