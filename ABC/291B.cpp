#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N;
    cin >> N;

    vector<int> X(5*N);
    for(auto &x : X) cin >> x;

    sort(X.begin(), X.end());
    int sum = 0;
    for(int i = 0; i < X.size(); i++){
        if(N < i+1 && i+1 <= X.size()-N){
            sum += X.at(i);
        }
    }

    double ave = (double)sum/(3*N);
    cout << fixed << setprecision(10) << ave << endl;
    return 0;
}