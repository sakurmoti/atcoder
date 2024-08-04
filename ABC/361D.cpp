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
    string S,T; cin >> S >> T;
    S += "##";
    T += "##";
    // cout << S << "\n" << T << endl;

    queue<pair<string, int>> que;
    set<string> visited;
    que.push(make_pair(S, 0));
    while(!que.empty()){
        auto[str, cnt] = que.front();
        que.pop();
        // cout << cnt << " " << str << endl;

        if(visited.contains(str)) continue;
        visited.insert(str);

        if(str == T){
            cout << cnt << '\n';
            return 0;
        }

        int blank = -1; // 2つ並ぶうちの最初の方
        for(int i = 0; i < N+2; i++){
            if(str[i] == '#'){
                blank = i;
                break;
            }
        }

        for(int i = 0; i < N+1; i++){
            if(str[i] == '#' || str[i+1] == '#') continue;
            
            
            string nxt = str;
            nxt[blank] = str[i];
            nxt[blank+1] = str[i+1];
            nxt[i] = '#';
            nxt[i+1] = '#';

            que.push(make_pair(nxt, cnt+1));
        }

    }

    cout << -1 << '\n';
    return 0;
}