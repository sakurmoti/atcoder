#include <bits/stdc++.h>
using namespace std;

bool isRev(string S){
    for(int i = 0; i < S.size(); i++){
        if(S.at(i) != S.at(S.size()-1-i)){
            return false;
        }
    }
    return true;
}

int main(){
    int N;
    long long A,B;
    cin >> N >> A >> B;

    string S;
    cin >> S;

    S += S;

    //行動Aをしても文字の順番は変わらない -> N回以内
    //行動Aをi回したのちにBをして回文にしたときのコストを全探索
    long long ans = 1e18;
    for(int i = 0; i < N; i++){
        long long cost = i*A;
        string temp = S.substr(i, N);

        //異なっているところを全て行動Bする
        for(int j = 0; j < N; j++){
            if(N-1-j < j) break;

            if(temp.at(j) != temp.at(N-1-j)){
                cost += B;
            }
        }
        
        ans = min(ans, cost);
    }

    cout << ans << endl;
    return 0;
}