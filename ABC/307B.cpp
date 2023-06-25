#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i==j) continue;

            string T = S[i] + S[j];
            bool flag = true;
            for(int k = 0; k < T.size(); k++){
                if(T[k] != T[T.size()-1-k]){
                    flag = false;
                }
            }

            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}