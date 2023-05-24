#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    set<char> balls;
    stack<set<char>> buf;

    for(int i = 0; i < S.size(); i++){
        char c = S.at(i);

        if(c == '('){
            buf.push(balls);
            continue;
        
        }else if(c == ')'){
            //Rollback
            balls = buf.top();
            buf.pop();

        }else{
            if(balls.count(c)){
                cout << "No" << endl;
                return 0;
            
            }else{
                balls.insert(c);

            }

        }

    }

    cout << "Yes" << endl;
    return 0;
}