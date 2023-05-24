#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> ans(N+1);
    int A,B;
    for(int i = 0; i < M; i++){
        cin >> A >> B;
        ans.at(A).push_back(B);
        ans.at(B).push_back(A);
    }

    for(int i = 1; i <= N; i++){
        cout << ans.at(i).size();
        if(ans.at(i).size() == 0) cout << endl;
        else cout << " ";

        sort(ans.at(i).begin(), ans.at(i).end());
        for(int k = 0; k < ans.at(i).size(); k++){
            cout << ans.at(i).at(k);
                
            if(k != ans.at(i).size()-1) cout << " ";
            else cout << endl;
        }
    }
    
    return 0;
}