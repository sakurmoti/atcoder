#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;

    long long same=0;
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
        a.at(i)--; //0を基準にするため1減らす
        if(a.at(i) == i) same++;
    }

    long long count = (same*(same-1))/2;
    for(int i = 0; i < N-1; i++){
        if(a.at(i) == i){
            /*同じペアがn組あるなら答えとなるのは
            1と2,3,4..nのn-1組、2と3,4,5..nのn-2組のように
            n-1までの総和と同じ数になる。だから上でcountをこのように初期化した*/

        //もうひとつのパターンはa_i == j && a_j ==iのとき、つまりa_(a_i) ==i
        }else if(a.at(a.at(i)) == i){
            if(i < a.at(i)) //i < jを忘れずに
            count++;
        }
    }

    cout << count << endl;
    return 0;
}