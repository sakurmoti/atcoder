#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    cin >> N;

    long long ans = 0;

    //ABの全パターンを探す
    long long tmp = 0;
    map<long long, int> comb;
    for(int A = 1; A <= N; A++){
        for(int B = 1; B <= N; B++){
            if(N <= A*B) break;

            //printf("A*B = %d\n", A*B);
            comb[A*B]++;
        }
    }

    for(int i = 1; i <= N; i++){
        if(comb.find(i) != comb.end() && comb.find(N-i) != comb.end()){
            //AB+CDなる組合せが存在する
            //printf("comb[%d] = %d, comb[%d] = %d\n", i,comb[i],N-i, comb[N-i]);
            ans += (comb.at(i) * comb.at(N-i));
        }
    }

    cout << ans << endl;
    return 0;
}