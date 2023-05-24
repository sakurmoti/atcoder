#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long T;
    cin >> N >> T;

    vector<int> A(N);
    long long sumA=0;
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        sumA += A.at(i);
    }

    //1週して戻ってきても同じ
    T %= sumA;

    //あとはどこで曲が終わるか確かめるだけO(N)
    for(int i = 0; i < N; i++){
        T -= A.at(i);

        if(T < 0){
            //i番目の曲で秒数がなくなったのでi番目で終わるということ
            //1-idxになおす
            cout << i+1 << " " << T+A.at(i) << endl;
            break;
        }
    }

    return 0;
}