#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    string S;
    cin >> S;

    int flag = 0;
    for(int i = 0; i < N; i++){
        char c = S.at(i);

        if(c == '"'){
            flag++;
            continue;
        }

        if(flag % 2 == 0){
            if(c == ','){
                S.at(i) = '.';
            }
        }

    }

    cout << S << endl;
    return 0;
}