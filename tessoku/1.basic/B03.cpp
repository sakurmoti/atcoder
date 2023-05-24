#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A.at(i);

    bool flag = false;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            for(int k = j+1; k < N; k++){
                if(A.at(i) + A.at(j) + A.at(k) == 1000) flag = true;
            }
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}