#include <bits/stdc++.h>
using namespace std;

int main(){
    char p,q;
    cin >> p >> q;

    int dist[] = {3,1,4,1,5,9};
    int a = p-'A';
    int b = q-'A';

    if(b < a){
        swap(a,b);
    }

    int ans = 0;
    for(int i = a; i < b; i++){
        ans += dist[i];
    }
    cout << ans << endl;
    return 0;
}