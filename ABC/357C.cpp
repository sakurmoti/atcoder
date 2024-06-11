#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

void make_carpet(vector<string> &carpet, int level, int y, int x, int len){
    if(level == 0) return;

    int L = len/3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i==1 && j==1){
                for(int k = 0; k < L; k++){
                    for(int l = 0; l < L; l++){
                        carpet[y+L+k][x+L+l] = '.';
                    }
                }
            }else{
                make_carpet(carpet, level-1, y+i*L, x+j*L, L);
            }
        }
    }
}

int main(){
    int N; cin >> N;

    ll width = 1;
    for(int i = 0; i < N; i++){
        width *= 3;
    }

    vector<string> carpet(width, string(width, '#'));
    make_carpet(carpet, N, 0, 0, width);

    for(auto &_v : carpet){ for(auto &_vv : _v) cout << _vv; cout << endl; }
    return 0;
}