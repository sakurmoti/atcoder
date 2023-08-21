#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int M; cin >> M;

    ll sum = 0;
    vector<int> D(M+1, 0);
    for(int i = 1; i <= M; i++){
        cin >> D[i];
        sum += D[i];
    }
    
    int mid = sum/2;
    int cnt = 0;
    for(int i = 1; i <= M; i++){
        for(int d = 1; d <= D[i]; d++){
            if(mid == cnt){
                cout << i << " " << d << endl;
            }
            cnt++;
        }
    }
    return 0;
}