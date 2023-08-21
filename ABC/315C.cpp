#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<pair<int, int>> ice(N);
    for(int i = 0; i < N; i++){
        cin >> ice[i].second >> ice[i].first;
    }
    
    sort(ice.rbegin(), ice.rend());

    pair<int, int> ice1 = ice[0];
    int flavor1 = ice1.second;

    int ice2 = -1;
    for(int i = 1; i < N; i++){
        if(ice[i].second == flavor1){
            ice[i].first /= 2;
        }

        ice2 = max(ice2, ice[i].first);
    }

    cout << ice1.first + ice2 << endl;
    return 0;
}