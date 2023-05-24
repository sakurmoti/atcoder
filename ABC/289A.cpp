#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(s.at(i) == '1') cout << 0;
        else cout << 1;
    }

    return 0;
}