#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

// 「高橋君は青木君に1度も負けなかった」が無ければ通る
int main(){
    int N; cin >> N;
    string S; cin >> S;

    map<char, char> dict;
    dict['R'] = 'P';
    dict['P'] = 'S';
    dict['S'] = 'R';
    
    string T = "";
    for(int i = 0; i < N; i++){
        T += dict[S[i]];
    }

    // ランレングス圧縮
    vector<int> comp;
    char prev = T[0];
    int cnt = 1;
    for(int i = 1; i < N; i++){
        if(prev == T[i]){
            cnt++;
        }else{
            comp.push_back(cnt);
            cnt = 1;
            prev = T[i];
        }
    }
    comp.push_back(cnt);

    cout << T << endl;
    for(auto &_v : comp) cout << _v << " "; cout << endl;
    
    int ans = 0;
    for(int i = 0; i < comp.size(); i++){
        ans += (comp[i]+1)/2;
    }
    cout << ans << endl;
    return 0;
}