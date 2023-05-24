#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<pair<int,int>> LR(N);
    for(int i = 0; i < N; i++){
        cin >> LR[i].first >> LR[i].second;
    }

    sort(LR.begin(), LR.end(), [](auto i, auto j){return i.second < j.second;});

    int now = 0;
    int ans = 0;
    //終演時間の速い順に並べているので、現在が開演時間より先であれば貪欲にみる
    for(int i = 0; i < N; i++){
        if(now <= LR.at(i).first){
            now = LR.at(i).second;
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}