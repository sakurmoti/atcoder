#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    stack<int> st;
    for(int i = 0; i < S.size(); i++){
        char c = S.at(i);

        if(c == '('){
            st.push(i+1); //1-idxにしている

        }else if(c == ')'){
            int L = st.top();
            st.pop();

            int R = i+1;

            cout << L << " " << R << endl; //必ずRのほうがLより大きく、Rは単調増加なのだからこれは出力の条件を満たす
            
        }
    }
    return 0;
}