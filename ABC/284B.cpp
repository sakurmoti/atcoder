#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int test = 0; test < T; test++){
        int N, ans=0;
        cin >> N;

        int a;
        for(int i = 0; i < N; i++){
            cin >> a;
            if(a%2 == 1){
                ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}