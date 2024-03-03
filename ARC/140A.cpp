#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,K; cin >> N >> K;
    string S; cin >> S;

    // f(T)はO(N)で求まる
    // Tを任意の区間Lで繰り返しになるようにすればf(T)は減少する
    // Lが短くなるほどf(T)は小さい

    // set<string> st;
    // for(int i = 0; i < N; i++){
    //     string T = S.substr(i, N-i) + S.substr(0, i);
    //     cout << T << endl;
    //     st.insert(T);
    // }

    for(int l = 1; l <= N; l++){
        if(N%l != 0) continue;

        int cnt = 0;
        for(int i = 0; i < l; i++){
            vector<int> v(30,0);
            int sum = 0;
            for(int j = i; j < N; j += l){
                v[S[j]-'a']++;
                sum++;
            }

            cnt += sum - *max_element(ALL(v));
        }

        if(cnt <= K){
            cout << l << endl;
            break;
        }
    }

    return 0;
}