#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<string> S(N);
    for(auto &_v : S) cin >> _v;

    int time = 1e9;
    for(char c = '0'; c <= '9'; c++){
        int t = 0;
        vector<bool> decided(N, false);
        bool flag = true;
        while(true){
            for(int i = 0; i < N; i++){
                if(S[i][t%10] == c && !decided[i]){
                    decided[i] = true;
                    break;
                }
            }

            flag = false;
            for(int i = 0; i < N; i++){
                if(!decided[i]) flag = true; 
            }

            if(flag) t++;
            else break;
        }

        time = min(time, t);
    }

    cout << time << endl;
    return 0;
}