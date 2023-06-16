#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string S;
    cin >> S;
    S.push_back('+'); //整形。最後に+0がついていると考える

    int cnt = 0;
    vector<int> buf;
    vector<vector<int>> formula;
    for(int i = 0; i < S.size(); i+=2){
        char num = S[i];
        char sign = S[i+1];

        // 足し算の項で分解
        buf.push_back(i);
        if(sign == '+'){
            formula.push_back(buf);
            buf.resize(0);
        }
    }

    for(auto v : formula){
        bool isZero = false;
        for(auto x : v){
            // cout << x << " ";
            if(S[x] == '0') isZero = true;
        }
        if(!isZero) cnt++; //0でないなら書き換える必要あり
        // cout << endl;
    }
    cout << cnt << endl;

    return 0;
}