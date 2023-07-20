#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S,T;
    cin >> S >> T;

    //Sの大きさをNとすると最大N回操作を繰り返せばよい
    int N = S.size();
    S += S;
    for(int st = 0; st < N; st++){
        bool flag = true;
        for(int i = 0; i < N; i++){
            if(T[i] != S[N-st+i]) flag = false;
        }

        if(flag){
            cout << st << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}