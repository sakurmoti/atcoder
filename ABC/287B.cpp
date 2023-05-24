#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<string> dic; 
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;

        string buf = S.substr(3,3);
        dic.push_back(buf);
    }

    int cnt = 0;
    set<string> st;
    for(int i = 0; i < M; i++){
        string T;
        cin >> T;

        st.insert(T);
    }

    for(int i = 0; i < N; i++){
        if(st.count(dic.at(i))) cnt++;
    }

    cout << cnt << endl;
    return 0;
}