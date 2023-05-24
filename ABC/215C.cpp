#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    int K;
    cin >> S >> K;

    //sortして1番目の文字列にする
    sort(S.begin(), S.end());

    //next_permutationで辞書順で次の順列を生成する
    for(int i = 1; i < K; i++){
        next_permutation(S.begin(), S.end());
    }

    cout << S << endl;

    return 0;
}