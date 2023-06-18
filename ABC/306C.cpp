#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> A(3*N);
    for(int i = 0; i < 3*N; i++){
        cin >> A[i];
    }

    map<int, int> dict;
    vector<int> ans;
    for(int i = 0; i < 3*N; i++){
        int a = A[i];
        dict[a]++;
        if(dict[a] == 2){
            ans.push_back(a);
        }

    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << " \n"[i == N-1];
    }
    return 0;
}