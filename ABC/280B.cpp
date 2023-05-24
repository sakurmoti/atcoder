#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<long long> ans;
    long long s,s_0;
    
    cin >> s_0;
    ans.push_back(s_0);
    for(int i = 1; i < N; i++){
        cin >> s;
        ans.push_back(s - s_0);
        s_0 = s;
    }

    for(int i = 0; i < N; i++){
        cout << ans.at(i);
        
        if(i == N-1) cout << endl;
        else cout << " ";
    }
    return 0;
}