#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    ll N,T; cin >> N >> T;
    string S; cin >> S;
    vector<ll> X(N);
    for(auto &_v : X) cin >> _v;

    vector<ll> m_ants, p_ants;
    for(int i = 0; i < N; i++){
        if(S[i] == '0'){
            m_ants.push_back(X[i]);
        }else{
            p_ants.push_back(X[i]);
        }
    }

    sort(ALL(m_ants));
    sort(ALL(p_ants));

    // for(auto &_v : m_ants) cout << _v << " "; cout << endl;
    // for(auto &_v : p_ants) cout << _v << " "; cout << endl;

    auto latest_p_ants = p_ants;
    for(auto &v : latest_p_ants){
        v += T;
    }

    // for(auto &_v : p_ants) cout << _v << " "; cout << endl;

    ll ans = 0;
    for(auto &v : m_ants){
        ll cnt1 = lower_bound(ALL(p_ants), v) - p_ants.begin();
        ll cnt2 = lower_bound(ALL(latest_p_ants), v-T) - latest_p_ants.begin();

        ans += cnt1 - cnt2;
        // cout << cnt1 << " " <<  cnt2 << endl;
    }

    cout << ans << endl;
    return 0;
}