#include <bits/stdc++.h>
using namespace std;

stack<string> st;

void query(){
    int q;
    cin >> q;

    if(q == 1){
        string x;
        cin >> x;

        st.push(x);

    }else if(q == 2){
        cout << st.top() << endl;

    }else{
        st.pop();

    }
}

int main(){
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        query();
    }
    return 0;
}