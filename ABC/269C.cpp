#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;

    bitset<60> N_bit(N);
    //cout << N_bit << endl;

    vector<long long> ans(1,0); //配列ansに1となったところを記憶させていって徐々に増やすイメージ
    int ans_size = 1; //push_backするので.size()を使うと無限ループしちゃう

    for(int i = 0; i < 60; i++){
        if(N_bit.test(i)){
            for(int j = 0; j < ans_size; j++){
                ans.push_back(((long long)1 << i) + ans.at(j));
            }

            ans_size = ans.size();
        }
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans.at(i) << endl;
    }
    return 0;
}