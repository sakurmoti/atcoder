#include <bits/stdc++.h>
using namespace std;

bool isMatch(char a, char b){
    return (a == '?' || b == '?' || a == b);
}

int main(){
    string S,T;
    cin >> S >> T;

    //prefixは先頭からi文字見たときにマッチしているか、suffixは後ろからi文字見たときにマッチしているか
    vector<bool> prefix(T.size()+1, false), suffix(T.size()+1, false);
    prefix[0] = true;
    suffix[0] = true;
    for(int i = 0; i < T.size(); i++){
        //一度でもマッチしないところがあればその後はずっとマッチしない
        if(isMatch(S[i],T[i])) prefix.at(i+1) = true;
        else break;
    }

    //逆もみる
    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());
    for(int i = 0; i < T.size(); i++){
        if(isMatch(S[i],T[i])) suffix.at(i+1) = true;
        else break;
    }

    for(int i = 0; i <= T.size(); i++){
        if(prefix[i] && suffix[T.size()-i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;
}