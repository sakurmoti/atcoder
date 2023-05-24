#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    long long x;
    pair<int, int> ans = {-1, -1};

    for(int d = 1; d <= 9; d++){
        x = 0;
        for(int n = 1; n <= N; n++){
            x = (10 * x + d) % M;

            if(x == 0){
                ans = max(ans, pair<int,int>({n,d}));
            }
        }
    }

    if(ans.first != -1){
        for(int i = 0; i < ans.first; i++){
            cout << ans.second;
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}