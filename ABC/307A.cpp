#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < 7; j++){
            int a; cin >> a;
            sum += a;
        }
        cout << sum << " \n"[i==N-1];
        
    }

    return 0;
}