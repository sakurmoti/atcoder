#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    set<int> st;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        st.insert(a);
    }

    cout << *(next(st.rbegin())) << endl;
    return 0;
}