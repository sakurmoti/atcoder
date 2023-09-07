#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M,P;
    cin >> N >> M >> P;

    int cnt = 0;
    for(int i = 1; i <= N; i++){
        ll day = M + cnt*P;
        if(i == day){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}