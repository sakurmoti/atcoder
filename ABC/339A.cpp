#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    
    deque<char> T;
    for(int i = S.size()-1; i >= 0; i--){
        if(S[i] != '.'){
            T.push_front(S[i]);
        }else{
            break;
        }
    }

    for(int i = 0; i < T.size(); i++){
        cout << T[i];
    }
    cout << endl;
    return 0;
}