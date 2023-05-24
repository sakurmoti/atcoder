#include <bits/stdc++.h>
using namespace std;

int N,Q;
bool isRev = false; //反転したときtrue
vector<int> A;


void Query(){
    int command, x, y;
    cin >> command;

    if(command == 1){
        cin >> x >> y;
        if(isRev) x = A.size()-x; //反転したら上からx番目とする
        
        A.at(x) = y;

    }else if(command == 2){
        isRev = !isRev; //反転を記録

    }else if(command == 3){
        cin >> x;
        if(isRev) x = A.size()-x;

        cout << A.at(x) << endl;

    }
}

int main(){
    cin >> N >> Q;

    A.resize(N+1);
    for(int i = 0; i <= N; i++) A.at(i) = i;

    for(int i = 0; i < Q; i++){
        Query();
    }
    return 0;
}