#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> P(N);
    
    int M = -1;
    for(int i = 0; i < N; i++){
        cin >> P[i];

        if(i!=0){
            M = max(M,P[i]);
        }
    }

    cout << max(0, M-P[0]+1) << endl;
    return 0;
}