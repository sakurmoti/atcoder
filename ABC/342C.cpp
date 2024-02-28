#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    string S; cin >> S;

    int Q; cin >> Q;
    map<char, char> dict;
    for(char i = 'a'; i <= 'z'; i++) dict[i] = i;

    while(Q--){
        char c,d;
        cin >> c >> d;

        for(char i = 'a'; i <= 'z'; i++){
            if(dict[i]==c){
                dict[i] = d;
            }
        }
    }

    for(int i = 0; i < N; i++){
        cout << dict[S[i]];

    }
    return 0;
}