#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> bit(M,1);
    for(int i = 0; i < N; i++){
        bit.at(i) = 0;
    }

    sort(bit.begin(), bit.end());

    do{
        for(int i = 0; i < M; i++){
            if(bit.at(i)==0){
                cout << i+1 << " ";
            }
        }
        cout << endl;

    }while(next_permutation(bit.begin(), bit.end()));

    return 0;
}