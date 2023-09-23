#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> num;
void make_like(ll x){
    num.push_back(x);
    
    for(int i = 1; i <= 9; i++){
        ll y = (x%10) - i;
        if(y < 0) return;

        ll next = x*10 + y;
        // cout << next << endl;
        make_like(next);
    }
}

int main(){
    int K; cin >> K;
    for(int i = 1; i < 10; i++){
        make_like(i);
    }

    // for(int i = 0; i < num.size(); i++) cout << num[i] << endl;

    sort(num.begin(), num.end());

    // for(int i = 0; i < num.size(); i++) cout << num[i] << endl;

    cout << num[K-1] << endl;
    return 0;
}