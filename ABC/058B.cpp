#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string O,E;
    cin >> O >> E;

    vector<char> pass(200, '0');
    for(int i = 0; i < O.size(); i++){
        pass.at((2*i)) = O[i];
    }

    for(int i = 0; i < E.size(); i++){
        pass.at(2*i+1) = E[i];
    }

    int i = 0;
    while(pass[i] != '0'){
        cout << pass[i];
        i++;
    }
    return 0;
}