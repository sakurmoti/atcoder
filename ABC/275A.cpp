#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int H;
    cin >> H;

    int ans = 1;
    int maxH = H;;
    for(int i = 2; i <= N; i++){
        cin >> H;
        if(H > maxH){
            ans = i;
            maxH = H;
        }
    }

    cout << ans << endl;
    return 0;
}