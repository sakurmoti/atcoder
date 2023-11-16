#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> D(N);
    for(auto &_v : D) cin >> _v;

    int ans = 0;
    for(int i = 0; i < N; i++){
        string month = to_string(i+1);
        char num = month[0];
        for(int day = 1; day <= D[i]; day++){
            string d = to_string(day);

            string b = month + d;
            bool zoro = true;
            for(int j = 0; j < b.size(); j++){
                if(b[j] != num) zoro = false;
            }

            if(zoro) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}