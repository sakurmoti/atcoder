#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<int> A(N,1), B(N,1); //元々全て大きさ1とする
    for(int i = 0; i < S.size(); i++){
        char c = S.at(i);

        //条件Aによって考えうる下限値
        if(c == 'A'){
            A.at(i+1) = A.at(i) + 1; //前の草より1だけ大きいのが最小
            
        }else{
            A.at(i+1) = 1; //前の草より小さくて良いので1にしておく

        }
    }

    for(int i = S.size()-1; i >=0; i--){
        char c = S.at(i);

        //条件Bによって考えうる下限値
        if(c == 'B'){
            B.at(i) = B.at(i+1) + 1; //後ろの草より1だけ大きいのが最小
            
        }else{
            B.at(i) = 1; //後ろの草より小さくて良いので1にしておく

        }
    }

    //条件A,Bを共にみたすような下限値を取ればよい
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += max(A.at(i), B.at(i));
        //printf("%d\n",max(A.at(i), B.at(i)));
    }
    cout << ans << endl;
    return 0;
}