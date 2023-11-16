#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    stack<pair<int, int>> st;
    st.push(make_pair(-1, -1));
    for(int i = 0; i < N; i++){
        pair<int, int> top = st.top();
        if(top.first == A[i]){
            // この球を置けばA[i]がA[i]個連続する
            if(top.second == A[i]-1){
                for(int j = 0; j < top.second; j++){
                    st.pop();
                }
            }else{
                st.push(make_pair(A[i], top.second+1));
            }

        }else{
            st.push(make_pair(A[i], 1));
        }

        cout << st.size()-1 << endl;
    }
    return 0;
}