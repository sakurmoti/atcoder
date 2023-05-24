#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<bool> test(N+1, false);
    vector<bitset<10>> C(M);
    for(int i = 0; i < M; i++){
        int q; cin >> q;

        C.at(i).set();
        for(int j = 0; j < N; j++) C.at(i).reset(j);

        for(int j = 0; j < q; j++){
            int buf;
            cin >> buf;
            buf--;

            C.at(i).set(buf);
        }
    }

    int cnt = 0;
    for(int i = 0; i < (1 << M); i++){
        bitset<10> buf(i);
        
        bitset<10> ans;
        ans.reset();

        for(int j= 0; j < 10; j++){
            if(buf.test(j)){
                ans |= C.at(j);
            }
        }

        if(ans.all()) cnt++;
    }

    cout << cnt << endl;

    return 0;
}