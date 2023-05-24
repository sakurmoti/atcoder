#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    
    vector<vector<int>> imos(2000, vector<int>(2000,0));
    int x,y;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        imos.at(y).at(x)++;
    }

    //行の累積和
    for(int i = 1; i < 2000; i++){
        for(int j = 1; j < 2000; j++){
            imos.at(i).at(j) += imos.at(i).at(j-1);
        }
    }

    //列の累積和
    for(int j = 1; j < 2000; j++){
        for(int i = 1; i < 2000; i++){
            imos.at(i).at(j) += imos.at(i-1).at(j);
        }
    }

    int a,b,c,d,Q;
    cin >> Q;

    for(int i = 0; i < Q; i++){
        cin >> a >> b >> c >> d;

        cout << imos.at(d).at(c) + imos.at(b-1).at(a-1) - imos.at(d).at(a-1) - imos.at(b-1).at(c) << endl;
    }
    return 0;
}