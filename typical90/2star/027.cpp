#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    string S;
    map<string, int> dic;
    for(int i = 1; i <= N; i++){
        cin >> S;
        
        if(!dic.count(S)){
            cout << i << endl;
            dic[S] = 0;
        }
    }

    return 0;
}