#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x, y;};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,Q; cin >> N >> Q;
    string S; cin >> S;

    int cnt = 0;
    vector<pair<int, int>> used(N, {-1,-1});
    for(int i = 0; i < N-2; i++){
        if(S[i]=='A' && S[i+1]=='B' && S[i+2]=='C'){
            cnt++;
            used[i] = make_pair(i+1,i+2);
            used[i+1] = make_pair(i,i+2);
            used[i+2] = make_pair(i,i+1);
        }
    }

    while(Q--){
        int x; cin >> x;
        char c; cin >> c;

        x--;

        if(used[x].first != -1){
            cnt--;
            auto[i,j] = used[x];
            used[i] = make_pair(-1,-1);
            used[j] = make_pair(-1,-1);
            used[x] = make_pair(-1,-1);
        }

        S[x] = c;
        for(int j = -2; j <= 0; j++){
            int i = x+j;
            if(isRange(i, 0, N-2)){
                if(S[i]=='A' && S[i+1]=='B' && S[i+2]=='C' && used[i].first==-1 && used[i+1].first==-1 && used[i+2].first==-1){
                    cnt++;
                    used[i] = make_pair(i+1,i+2);
                    used[i+1] = make_pair(i,i+2);
                    used[i+2] = make_pair(i,i+1);
                }
            }
        }

        cout << cnt << endl;
    }
    return 0;
}