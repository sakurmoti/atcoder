#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    deque<char> T;
    for(int i = 0; i < S.size(); i++){
        T.push_back(S[i]);
    }

    for(int i = 0; i < (int)T.size()-2; i++){
        char a = T[i];
        char b = T[i+1];
        char c = T[i+2];

        if(a == 'A' && b == 'B' && c == 'C'){
            T.erase(T.begin() + i, T.begin() + i+3);
            i = max(-1, i-3); //次にi-2から始めたいので
        }
    }

    for(int i = 0; i < T.size(); i++){
        cout << T[i];
    }
    return 0;
}