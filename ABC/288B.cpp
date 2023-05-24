#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<string> name;
    for(int i = 0; i < N; i++){
        string S;
        cin >> S;

        if(i < K) name.push_back(S);
    }

    sort(name.begin(), name.end());

    for(int i = 0; i < K; i++){
        cout << name.at(i) << endl;
    }
    return 0;
}