#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<long long> A(N+1);
    for(int i = 1; i <= N; i++) cin >> A.at(i);

    int Q;
    cin >> Q;

    int command,all,add,idx;
    vector<bool> isAdd(N+1, true); //代入したあと加算したかどうか。最初はtrueでよい
    for(int query = 0; query < Q; query++){
        cin >> command;

        if(command == 1){
            cin >> all;

            //配列のresize(N+1,false)としても全てfalseにはならず、元の配列より長くなった分がfalseになる
            //そこでいったん配列の大きさを0にすることで無理やり初期化する
            isAdd.resize(0);
            isAdd.resize(N+1, false);

        }else if(command == 2){
            cin >> idx >> add;
            //代入されたことあるなら足すだけ。ないなら代入した後加算
            if(isAdd.at(idx)){
                A.at(idx) += add;
            
            }else{
                A.at(idx) = all+add;
                isAdd.at(idx) = true;
            }

        }else if(command == 3){
            cin >> idx;
            //加算したことあるならそのままidxを、ないならallを入れればよい
            if(isAdd.at(idx)) cout << A.at(idx) << endl;
            else cout << all << endl;

        }
    }

    return 0;
}