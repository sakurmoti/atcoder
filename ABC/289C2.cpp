#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M; cin >> N >> M;
    vector<bitset<10>> C(M);
    for(int i = 0; i < M; i++){
        int c; cin >> c;
        for(int j = 0; j < c; j++){
            int a; cin >> a;
            a--;
            C[i].set(a);
        }
    }

    int ans = 0;
    for(int i = 0; i < (1<<M); i++){
        bitset<10> select(i);
        bitset<10> t(0);
        for(int j = 0; j < 10; j++){
            if(select.test(i)){
                t |= C[j];
            }
        }

        if(t.all()){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}