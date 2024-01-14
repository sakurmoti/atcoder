#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    bitset<40> ctz(N);
    int cnt = 0;
    for(int i = 0; i < 40; i++){
        if(!ctz.test(i)){
            cnt++;
        }else{
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}