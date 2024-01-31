#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    // 1010
    // 0110

    // 100 101 10
    // 010 110 10
    // 001 011 10

    // 2^M >= NになるM人を呼ぶ
    // M >= log_2(N)
    int M = ceill(log2l(N));
    cout << M << endl;

    // bits[i] := ジュースiを飲ませる人
    vector<bitset<10>> bits(N);
    for(int i = 0; i < N; i++){
        bits[i] = bitset<10>(i);
        // cout << bits[i] << endl;
    }

    vector<bitset<100>> people(M);
    for(int i = 0; i < M; i++){
        people[i].reset();

        for(int j = 0; j < N; j++){
            if(bits[j].test(i)){
                people[i].set(j);
            }
        }

        int cnt = people[i].count();
        cout << cnt;
        for(int j = 0; j < N; j++){
            if(people[i].test(j)){
                cout << " " << j+1;
            }
        }
        cout << endl;
    }

    string S; cin >> S;
    for(int i = 0; i < N; i++){
        bool ans = true;
        string str = bits[i].to_string();
        // cout << str << endl;
        for(int j = 0; j < M; j++){
            // cout << str[9-j];
            if(S[j] != str[9-j]){
                ans = false;
            }
        }
        // cout << endl;

        if(ans){
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}