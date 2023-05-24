#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N+1);
    for(int i = 1; i <= N; i++) cin >> A.at(i);

    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++){
        int sign;
        cin >> sign;

        if(sign == 1){
            int k,x;
            cin >> k >> x;
            A.at(k) = x;

        }else if(sign == 2){
            int k;
            cin >> k;
            cout << A.at(k) << endl;

        }

    }
    return 0;
}