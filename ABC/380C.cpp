#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};
struct Point{int x,y; Point(){}; Point(int _x, int _y):x(_x),y(_y){}};
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,K; cin >> N >> K;
    string S; cin >> S;

    vector<pair<int, int>> A;
    int cnt = 1, flag = S[0]-'0';
    int firstflag = flag;
    for(int i = 1; i < N; i++){
        if(S[i] == '1' && flag == 1){
            cnt++;
        }else if(S[i] == '0' && flag == 0){
            cnt++;
        }else{
            A.push_back(make_pair(flag, cnt));
            cnt = 1;
            flag = S[i]-'0';
        }
    }
    if(cnt > 0){
        A.push_back(make_pair(flag, cnt));
    }

    // for(auto [f,s] : A){
    //     cout << f << " " << s << endl;
    // }cout << endl;

    if(firstflag == 0){
        swap(A[2*K-1], A[2*K-2]);

    }else{
        K--;
        swap(A[2*K], A[2*K-1]);
    }

    for(auto [f,s] : A){
        // cout << f << " " << s << endl;
        cout << string(s, f+'0');
    }cout << endl;
    return 0;
}