#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    string S; cin >> S;

    if(S == "b"){
        cout << 0 << endl;
        return 0;
    }

    deque<char> T = {'b'};
    int cnt=0;
    for(int i = 1; i <= N; i++){
        if(i%3 == 1){
            T.push_front('a');
            T.push_back('c');

        }else if(i%3 == 2){
            T.push_back('a');
            T.push_front('c');

        }else if(i%3 == 0){
            T.push_back('b');
            T.push_front('b');

        }
        cnt++;

        if(T.size() >= S.size()) break;
    }

    for(int i = 0; i < N; i++){
        if(T[i] != S[i] || T.size() != S.size()){
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << cnt << endl;
    return 0;
}