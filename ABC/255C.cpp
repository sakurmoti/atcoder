#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

long long X,A,D,N;

long long S(long long n){
    return A + (n-1)*D;
}

int main(){
    cin >> X >> A >> D >> N;
    
    //S_i = A + (i-1)*D
    //abs(X - S_i)を最小にするi

    //差はどこかで最小になったあと増え続ける -> 三分探索
    //参考:https://qiita.com/ganyariya/items/1553ff2bf8d6d7789127
    long long left = 1;
    long long right = N;
    while(abs(right - left) > 2){
        long long c1 = (left*2 + right)/3;
        long long c2 = (left + right*2)/3;

        //f(c1) < f(c2)なら[left,c1]には必ず答えはないというイメージ
        if(abs(X-S(c1)) < abs(X-S(c2))){
            right = c2;
        }else{
            left = c1;
        }

        //cout << left << " " << right << endl;
    }

    cout << min({abs(X-S(left)), abs(X-S(left+1)), abs(X-S(right))}) << endl;

    return 0;
}