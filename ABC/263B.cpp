#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int>P(N-1);
    for(int i = 0; i < N-1; i++){
        cin >> P.at(i);
    }

    //N×0の配列。Nが子、push_backするのがその親
    vector<vector<int>> tree(N);
    for(int i = 0; i < N-1; i++){
        tree.at(i+1).push_back(P.at(i)-1);
    }

    int n=tree.at(N-1).at(0);
    int ans=1;
    while(n != 0){
        n = tree.at(n).at(0);
        ans++;
    }

    cout << ans << endl;

    return 0;
}