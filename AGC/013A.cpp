#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    int count = 0;
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
    }

    for(int i = 0; i < N; i++){
        //同じなら変わるまで進めて良い
        //cout << i << endl;
        while(i < N-1 && a.at(i) == a.at(i+1)) i++;

        if(i < N-1 && a.at(i) < a.at(i+1)){
            //もし増加するなら増加し続ける限り進める
            //増加しなくなったら切れ目なのでcountを進める
            while(i < N-1 && a.at(i) <= a.at(i+1)) i++;
        
        }else{
            while(i < N-1 && a.at(i) >= a.at(i+1)) i++;

        }
        count++;

    }

    cout << count << endl;
    return 0;
}