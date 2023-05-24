#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    map<int,int> dic;
    long long ans = 0;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;

        ans += dic[a];
        dic[a]++;
    }
    

    cout << ans << endl;

    return 0;
}