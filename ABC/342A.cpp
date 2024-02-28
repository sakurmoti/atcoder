#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S;
    cin >> S;

    map<char, int> dict;
    for(int i = 0; i < S.size(); i++){
        dict[S[i]]++;
    }

    for(int i = 0; i < S.size(); i++){
        if(dict[S[i]] == 1){
            cout << i+1 << endl;
        }
    }
    return 0;
}