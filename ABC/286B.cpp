#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<char> ans;
    for(int i = 0; i < N-1; i++){
        if(S.at(i) == 'n' && S.at(i+1) == 'a'){
            ans.push_back('n');
            ans.push_back('y');

        }else{
            ans.push_back(S.at(i));

        }
    }
    ans.push_back(S.at(N-1));

    for(auto v : ans) cout << v;
    cout << endl;
    return 0;
}