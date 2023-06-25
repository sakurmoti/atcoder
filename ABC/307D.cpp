#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    stack<int> st;
    vector<int> ans(N,0);
    for(int i = 0; i < N; i++){
        if(S[i] == '(' ){
            st.push(i);
        
        }else if(S[i] == ')' ){
            if(!st.empty()){
                ans[st.top()] += 1;
                ans[i+1] += -1;
                st.pop();
            }
        
        }
    }

    for(int i = 0; i < N-1; i++){
        ans[i+1] += ans[i];
        // cout << ans[i];
    }

    for(int i = 0; i < N; i++){
        if(ans[i] <= 0) cout << S[i];
    }

    return 0;
}