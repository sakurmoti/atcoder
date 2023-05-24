#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    cin >> N;

    string S;
    cin >> S;

    set<pair<int, int>> visited;
    pair<int, int> now = make_pair(0,0);
    visited.insert(now);

    bool flag = false;
    for(int i = 0; i < N; i++){
        if(S.at(i) == 'R'){
            now.first++;

        }else if(S.at(i) == 'L'){
            now.first--;

        }else if(S.at(i) == 'U'){
            now.second++;

        }else if(S.at(i) == 'D'){
            now.second--;

        }

        if(visited.count(now)) flag = true;
        visited.insert(now);
    }

    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}