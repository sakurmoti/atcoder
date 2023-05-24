#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A.at(i);
    }

    //parents[i]にはアメーバiがアメーバ1に行くまでの回数
    vector<int> parents(2*(N+1), 0);
    for(int i = 1; i <= N; i++){
        parents.at(2*i) = parents.at(A.at(i)) + 1;
        parents.at(2*i + 1) = parents.at(A.at(i)) + 1;
    }

    for(int i = 1; i < parents.size(); i++){
        cout << parents.at(i) << endl;
    }


    return 0;
}