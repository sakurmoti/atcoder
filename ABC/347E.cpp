#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,Q; cin >> N >> Q;

    vector<ll> A(N,0);
    set<int> st;

    ll sum = 0;
    while(Q--){
        int x; cin >> x;
        x--;

        if(st.contains(x)){
            A[x] += sum;
            st.erase(x);

        }else{
            A[x] -= sum;
            st.insert(x);

        }

        // for(auto &_v : A) cout << _v << " "; cout << endl;

        sum += st.size();
    }

    for(int i = 0; i < N; i++){
        if(st.contains(i)){
            A[i] += sum;
        }
        
    }

    for(auto &_v : A) cout << _v << " "; cout << endl;
    return 0;
}