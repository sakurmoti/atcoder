#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;

    vector<tuple<int, int, int>> card(N);
    for(int i = 0; i < N; i++){
        int a,c; cin >> a >> c;
        card[i] = make_tuple(c,a,i+1);
    }

    sort(ALL(card));

    int Maxi = -1;
    set<int> st;
    for(int i = 0; i < N; i++){
        auto[f,s,t] = card[i];
        // cout << f << " " << s << " " << t << endl;

        if(Maxi > s){
            st.insert(t);
        }else{
            Maxi = s;
        }
    }

    vector<int> ans;
    for(int i = 0; i < N; i++){
        auto[f,s,t] = card[i];
        if(!st.contains(t)){
            ans.push_back(t);
        }
    }

    sort(ALL(ans));
    cout << ans.size() << endl;
    for(auto &_v : ans) cout << _v << " "; cout << endl;
    return 0;
}