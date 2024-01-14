#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N; cin >> N;
    if(N==1){
        // 例外
        cout << 0 << endl;
        return 0;
    }

    // 8番目の値24は5進数でいう12(5),つまり7(10)
    //0-idxに
    N--;

    deque<int> bit5;
    while(N!=0){
        int a = N%5;
        bit5.push_front(a);
        N/=5;
    }

    for(int i = 0; i < bit5.size(); i++){
        cout << 2*bit5[i];
    }
    cout << endl;
    return 0;
}