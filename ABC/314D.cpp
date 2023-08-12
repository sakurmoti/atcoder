#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    string S; cin >> S;
    int Q; cin >> Q;

    vector<int> t(Q),x(Q);
    vector<char> c(Q);
    for(int i = 0; i < Q; i++){
        cin >> t[i] >> x[i] >> c[i];
        x[i]--;
    }

    //最後に小文字か大文字にした奴だけみる
    int flag = 1; //1:操作なし 2:小文字 3:大文字
    int idx = 0; //その操作のidx
    for(int i = Q-1; i >= 0; i--){
        if(t[i] == 2 || t[i] == 3){
            idx = i;
            flag = t[i];
            break;
        }
    }

    // printf("flag = %d, last idx = %d\n",flag, idx);

    for(int i = 0; i < idx; i++){
        if(t[i] == 1){
            S[x[i]] = c[i];
        }
         //大文字、小文字の処理はどうせ変わるからskip
    }

    //すべて書き換え
    for(int i = 0; i < N; i++){
        if(flag == 2){
            S[i] = tolower(S[i]);
        }
        if(flag == 3){
            S[i] = toupper(S[i]);
        }
    }

    for(int i = idx; i < Q; i++){
        //すべてt[i] == 1のコマンドになっているはず
        if(t[i] == 1) S[x[i]] = c[i];
    }

    cout << S << endl;
    return 0;
}