#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    int N = S.size();

    set<string> st;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            string T = S.substr(i, j);
            st.insert(T);
        }
    }

    cout << st.size() << endl;
    return 0;
}