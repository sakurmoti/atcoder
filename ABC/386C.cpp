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
    int K; cin >> K;
    string S,T; cin >> S >> T;

    int lenS = S.size();
    int lenT = T.size();

    if(lenS == lenT){
        int cnt = 0;
        for(int i = 0; i < lenS; i++){
            if(S[i] != T[i]){
                cnt++;
            }
        }

        if(cnt <= 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }

    }else if(lenS + 1 == lenT){
        bool flag = true;
        for(int i = 0; i < lenT; i++){
            if(flag){
                if(S[i] != T[i]){
                    flag = false;
                }

            }else{
                if(S[i-1] != T[i]){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }

        cout << "Yes" << endl;

    }else if(lenS == lenT + 1){
        bool flag = true;
        for(int i = 0; i < lenS; i++){
            if(flag){
                if(S[i] != T[i]){
                    flag = false;
                }

            }else{
                if(S[i] != T[i-1]){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }

        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}