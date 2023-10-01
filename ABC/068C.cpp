#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M; cin >> N >> M;
    vector<int> a(M), b(M);
    for(int i = 0; i < M; i++){
        cin >> a[i] >> b[i];
    }

    set<int> st;
    for(int i = 0; i < M; i++){
        if(a[i] == 1){
            st.insert(b[i]);
        }
    }

    for(int i = 0; i < M; i++){
        if(b[i] == N){
            if(st.find(a[i]) != st.end()){
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}