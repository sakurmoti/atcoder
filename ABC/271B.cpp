#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;

    vector<vector<int>> a(N);
    for(int i = 0; i < N; i++){
        int L;
        cin >> L;

        for(int j = 0; j < L; j++){
            int tmp;
            cin >> tmp;
            a.at(i).push_back(tmp);
        }
    }

    for(int i = 0; i < Q; i++){
        int s,t;
        cin >> s >> t;

        cout << a.at(s-1).at(t-1) << endl;
    }
    return 0;
}