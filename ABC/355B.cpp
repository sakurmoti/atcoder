#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N,M; cin >> N >> M;
    set<int> A,B;
    vector<int> C;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        A.insert(a);
        C.push_back(a);
    }

    for(int i = 0; i < M; i++){
        int b; cin >> b;
        B.insert(b);
        C.push_back(b);
    }

    sort(ALL(C));

    for(int i = 0; i < C.size()-1; i++){
        int n = C[i];
        int m = C[i+1];

        if(A.contains(n) && A.contains(m)){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}