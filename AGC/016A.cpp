#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    int N = S.size();

    // aからzまで、一つに染める回数を全て調べる
    int ans = 1e9;
    for(char c = 'a'; c <= 'z'; c++){
        int cnt = 0;
        string T = S;

        while(true){
            // cout << cnt << " : " << T << endl;
            
            bool flag = true;
            for(int i = 0; i < T.size(); i++){
                if(T[i] != c){
                    flag = false;
                }
            }
            if(flag) break;

            string buf;
            for(int i = 1; i < T.size(); i++){
                if(T[i-1] == c || T[i] == c ){
                    buf += c;
                }else{
                    buf += T[i];
                }
            }

            T = buf;
            cnt++;
        }

        ans = min(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}