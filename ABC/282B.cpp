#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<bitset<40>> S(N);
    for(int i = 0; i < N; i++){
        //すべて1で初期化
        S.at(i).set();

        for(int j = 0; j < M; j++){
            char c;
            cin >> c;

            if(c == 'o'){
                S.at(i).set(j);
            
            }else{
                S.at(i).reset(j);

            }
        }
    }

    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            bitset<40> tmp = S.at(i) | S.at(j);
            if(tmp.all()){
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}