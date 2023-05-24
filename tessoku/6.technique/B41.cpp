#include <bits/stdc++.h>
using namespace std;

int main(){
    int X,Y;
    cin >> X >> Y;

    //X < Yとすると最後はY = X + yになる
    //これを繰り返してXとyの大きいほうをまた減算して両方1になればよい
    vector<pair<int,int>> ans;
    while(X > 1 || Y > 1){
        ans.push_back(make_pair(X,Y));
        if(X < Y){
            //Y = X + yより
            Y = Y-X;

        }else{
            X = X-Y;

        }
    }

    reverse(ans.begin(), ans.end());
    int K = ans.size();

    cout << K << endl;
    for(int i = 0; i < K; i++){
        cout << ans.at(i).first << " " << ans.at(i).second << endl;
    }
    return 0;
}