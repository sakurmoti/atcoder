#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    string S,T;
    cin >> S >> T;
    int N = S.size();

    string replace = "atcoder";

    map<char, int> cardS, cardT;
    sort(S.begin(), S.end());
    sort(T.begin(), T.end()); 
    for(int i = 0; i < N; i++){
        cardS[S[i]]++;
        cardT[T[i]]++;
    }

    for(char c = 'a'; c <= 'z'; c++){
        if(cardS[c] == cardT[c]){
            //文字数が同じならok
            //cout << "ok" << endl;
            continue;
        
        }else if(find(replace.begin(), replace.end(), c) != replace.end()){
            //"atcoder"なら@に置き換える
            int dist = abs(cardS[c]-cardT[c]);
            //cout << "dist " << dist << endl;
            if(cardS[c] < cardT[c]){
                cardS['@'] -= dist;

            }else{
                cardT['@'] -= dist;

            }

        }else{
            cout << "No" << endl;
            return 0;

        }
    }

    if(cardS['@'] >= 0 && cardT['@'] >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}