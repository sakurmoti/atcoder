#include <bits/stdc++.h>
using namespace std;

int main(){
    long long X,Y;
    cin >> X >> Y;

    X -= 2015;
    Y -= 2015;

    //XとYの公約数を見つければよい
    vector<long long> X_div;
    for(long long i = 1; i*i <= X; i++){
        if(X%i == 0){
            X_div.push_back(i);
            if(i*i != X) X_div.push_back(X/i);
        }
    }

    vector<long long> Y_div;
    for(long long i = 1; i*i <= Y; i++){
        if(Y%i == 0){
            Y_div.push_back(i);
            if(i*i != Y) Y_div.push_back(Y/i);
        }
    }

    sort(X_div.begin(), X_div.end());
    sort(Y_div.begin(), Y_div.end());

    for(int i = 0; i < X_div.size(); i++){
        auto itr = lower_bound(Y_div.begin(), Y_div.end(), X_div.at(i));
        if(itr != Y_div.end() && *itr == X_div.at(i)){
            cout << X_div.at(i) << endl;
        }
    }

    return 0;
}