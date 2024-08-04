#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,K; cin >> N >> K;
    string S; cin >> S;

    vector<int> P(N);
    iota(ALL(P), 0);

    ll cnt = 0;
    set<string> st;

    do
    {
        string T = "";
        for(int i = 0; i < N; i++){
            T.push_back(S[P[i]]);
        }

        if(st.contains(T)) continue;
        st.insert(T);
        // cout << T << endl;
        
        bool f = true;
        for(int i = 0; i <= N-K; i++){
            string subs = T.substr(i, K);
            
            if(subs == string(RALL(subs))){
                f = false;
                break;
            }
        }

        if(f) cnt++;
    } while (next_permutation(ALL(P)));
    
    cout << cnt << endl;
    return 0;
}