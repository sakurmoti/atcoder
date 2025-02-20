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
    vector<int> A(5);
    for(auto &_v : A) cin >> _v;

    vector<pair<int, string>> S(32);
    string T = "ABCDE";
    for(int b = 1; b < 32; b++){
        bitset<5> bits(b);

        int sum = 0;
        string name = "";
        for(int i = 0; i < 5; i++){
            if(bits.test(i)){
                sum += A[i];
                name += T[i];
            }
        }

        S[b] = make_pair(sum, name);
    }
    
    sort(ALL(S), [](const auto &a, const auto &b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    });

    for(int i = 0; i < 31; i++){
        cout << S[i].second << endl;
    }
    return 0;
}