#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,Q;
    cin >> N >> Q;

    map<int,int> card;
    for(int i = 0; i < Q; i++){
        int c,x;
        cin >> c >> x;

        if(c == 1){
            card[x]++;

        }else if(c == 2){
            card[x] += 2;
        
        }else{
            if(card[x] >= 2){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}