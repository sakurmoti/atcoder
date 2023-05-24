#include <bits/stdc++.h>
using namespace std;

int euqlid(int x, int y){
    if(y == 0) return x;
    else return euqlid(y, x%y);
}

int main(){
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
    }

    int GCD = euqlid(a.at(0), a.at(1));

    for(int i = 2; i < N; i++){
        GCD = euqlid(GCD, a.at(i));
    }
    
    bool flag = true;
    int ans = 0;
    for(int i = 0; i < N; i++){
        a.at(i) /= GCD;

        while(a.at(i)%2 == 0){
            a.at(i)/=2;
            ans++;
        }

        while(a.at(i)%3 == 0){
            a.at(i)/=3;
            ans++;
        }

        if(a.at(i) != 1){
            flag = false;
            break;
        }
    }

    if(flag) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}