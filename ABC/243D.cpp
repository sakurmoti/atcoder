#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,X;
    cin >> N >> X;
    string S;
    cin >> S;

    deque<char> move; 
    for(int i = 0; i < N; i++){
        if(S[i] == 'U'){
            if(move.empty()){
                move.push_back('U');
            }else{
                if(move.back() != 'U') move.pop_back();
                else move.push_back('U');
            }
        }

        if(S[i] == 'L') move.push_back('L');
        if(S[i] == 'R') move.push_back('R');
    }

    while(!move.empty()){
        char c = move.front();
        move.pop_front();
        // printf("c=%c, now=%lld\n",c,X);

        if(c=='U') X = X/2;
        if(c=='L') X = 2*X;
        if(c=='R') X = 2*X + 1;
    }

    cout << X << endl;
    return 0;
}