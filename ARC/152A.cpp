#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,L;
    cin >> N >> L;

    /*隣と一マス開けて座らせる。空けながら座って最後まで埋まったとき、そこから二人組が来たら帰ってしまう*/
    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        
        if(a == 1){
            //一マス空けて座らせる。それが無理なら空けながら座ってきたところに入れる(特別な操作はしなくてよい)
            L -= 2;

        }else if(a == 2){
            //一マス空けて座らせる。それが無理なら一マス開けずに座らせる。それも無理なら"No"
            if(2 < L) L -= 3;
            else if(L == 2) L -= 2;
            else{
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}