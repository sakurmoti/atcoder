#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N,A,B;
    cin >> N >> A >> B;

    if(A>B){
        cout << 0 << endl;

    }else if(N==1){
        if(A==B){
            cout << 1 << endl;

        }else{
            cout << 0 << endl;

        }

    }else{
        /*AとBを先に入れておく
        これにより残りのN-2個はA <= x <= Bから自由に選べる重複組み合わせ
        B-A+1種類からN-2個を取り出す重複組み合わせ (B-A+1) H (N-2)
        cout << repCombination(B-A+1, N-2) << "!"<< endl;
        
        っておもったけど...
        入力4 4 6に対して20 = 4 + 4 + 6 + 6 = 4 + 5 + 5 + 6なのでダメ...
        */

        /*最小は(A+B)+A*(N-2)、最大は(A+B)+B(N-2)
        その間の数は何か一つを+1すればどんな数でも作れる
        つまり...*/
        cout << (B-A)*(N-2) +1 << endl;
        
    }

    return 0;
}