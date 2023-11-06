#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int N = 9;

int main(){
    vector<vector<int>> A(N, vector<int>(N));
    for(auto &_v : A) for(auto &_vv : _v) cin >> _vv;

    // 1
    for(int i = 0; i < N; i++){
        set<int> st;
        for(int j = 0; j < N; j++){
            if(st.count(A[i][j])){
                cout << "No" << endl;
                return 0;
            }
            st.insert(A[i][j]);
        }
    }

    // 2
    for(int j = 0; j < N; j++){
        set<int> st;
        for(int i = 0; i < N; i++){
            if(st.count(A[i][j])){
                cout << "No" << endl;
                return 0;
            }
            st.insert(A[i][j]);
        }
    }

    // 3
    vector<pair<int, int>> start = {{0,0}, {0,3}, {0,6}, {3,0}, {3,3}, {3,6}, {6,0}, {6,3}, {6,6}};
    for(int g = 0; g < 9; g++){
        set<int> st;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int sty = start[g].first;
                int stx = start[g].second;

                if(st.count(A[sty+i][stx+j])){
                    cout << "No" << endl;
                    return 0;
                }
                st.insert(A[sty+i][stx+j]);
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}