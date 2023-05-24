#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;

    vector<int> a(N);
    int per = 1;
    int count = 0;
    bool flag = true;
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
        
        //すべての通し番号と値が一致しているならtrueのまま
        if(a.at(i) != i+1){
            flag = false;
        }

        //1から順に並ぶように配列を選ぶ
        if(a.at(i) == per){
            count++;
            per++;
        }
    }

    if(flag || count != 0){
        cout << N-count << endl;
    }else{
        cout << "-1" << endl;
    }


    return 0;
}