#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
template<class T> inline bool isRange(const T &x, const T &l, const T &r){ return l <= x && x < r; }
template<class T> inline bool chmin(T &a, const T &b){ if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, const T &b){ if(a < b){ a = b; return true; } return false; }

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    stack<ll> st;
    for(int i = 0; i < N; i++){
        ll next = A[i];
        while(!st.empty()){
            ll top = st.top();

            if(next == top){
                st.pop();
                next += 1;
            }else{
                break;
            }
        }

        st.push(next);
    }

    // while(!st.empty()){
    //     cout << st.top() << " ";
    //     st.pop();
    // }

    cout << st.size() << endl;
    return 0;
}