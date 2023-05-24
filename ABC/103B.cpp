#include <bits/stdc++.h>
using namespace std;

int main(){
    string S,T;
    cin >> S >> T;

    bool flag = false;
    for(int start = 0; start < S.size(); start++){
        string buf;
        //開始位置を全探索
        for(int i=start, count=0; count < S.size(); i++, count++){
            //start位置から文字列を取得。iはindexを指定するのでforの条件のために別にカウンタを用意
            if(i == S.size()){ // iがsizeを超えそうなら0に戻す(ループ)
                i = 0;
            }
            buf.push_back(S.at(i));
        }
        //cout << buf << endl;

        if(buf == T){
            flag = true;
            break;
        }
        
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}