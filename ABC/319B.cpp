#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;

    vector<char> ans(N+10, '-');
    for(int i = 0; i <= N; i++){
        for(int j = 1; j < 10; j++){
            if( N%j == 0 ){
                if((N/j) != 0 && i%(N/j) == 0){
                    ans.at(i) = j+'0';
                    break;
                }
            }
        }
    }

    for(int i = 0; i <= N; i++){
        cout << ans.at(i);
    }
    return 0;
}