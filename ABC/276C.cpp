#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> P(N);
    for(int i = 0; i < N; i++){
        cin >> P.at(i);
    }

    prev_permutation(P.begin(), P.end());

    for(int i = 0; i < P.size(); i++){
        cout << P.at(i);
        
        if(i != P.size()-1) cout << " ";
        else cout << endl;
    }


    return 0;
}