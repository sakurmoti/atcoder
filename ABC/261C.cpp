#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    
    vector<string> S(N);
    map<string, int> temp;
    for(int i = 0; i < N; i++){
        cin >> S.at(i);
    }

    for(int i = 0; i < N; i++){
        if(temp.count(S.at(i))){
            string buf = to_string(temp.at(S.at(i)));
            temp.at(S.at(i))++;
            S.at(i) += '(' + buf + ')';
        /*buf > S.at > mapの順だとSが書き換えられてmapにヒットしなくなる
        先にbufにいれてカウントしてあげる*/

        }else{
            temp[S.at(i)] = 1;
        }
    }

    for(int i = 0; i < N; i++) cout << S.at(i) << endl;
    return 0;
}