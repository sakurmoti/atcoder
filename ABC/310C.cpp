#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;

    set<string> st;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        string S; cin >> S;
        bool rev = true;
        for(int j = 0; j < S.size(); j++){
            if(!(S[j] == S[S.size()-1-j])){
                rev = false;
            }
        }
        if(!st.count(S)){
            if(rev) cnt++;
        }

        st.insert(S);
        reverse(S.begin(),S.end());
        st.insert(S);
    }

    cout << (st.size()+cnt)/2 << endl;
    return 0;
}