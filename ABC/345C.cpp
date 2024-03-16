#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    int N = S.size();

    // {
    //     // 愚直
    //     set<string> st;
    //     for(int i = 0; i < N; i++){
    //         for(int j = i+1; j < N; j++){
    //             string T = S;
    //             swap(T[i], T[j]);
    //             st.insert(T);
    //         }
    //     }

    //     for(auto t : st) cout << t << endl;
    //     cout << "true : " << st.size() << endl;

    // }

    // v[c][i] := cがi文字目までに何個存在するか
    vector<vector<int>> v(30, vector<int>(N+1, 0));

    for(int i = 1; i <= N; i++){
        for(char c = 'a'; c <= 'z'; c++){
            v[c-'a'][i] = v[c-'a'][i-1];
            if(S[i-1] == c){
                v[c-'a'][i]+=1;
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i <= N; i++){
        for(char c = 'a'; c <= 'z'; c++){
            if(S[i-1] != c) ans += v[c-'a'][N] - v[c-'a'][i];
        }

        // cout << ans << endl;
    }

    // 同じ文字同士のswap
    // swapする文字が違くても1個だけ
    for(char c = 'a'; c <= 'z'; c++){
        if(v[c-'a'][N] >= 2){
            ans++;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}