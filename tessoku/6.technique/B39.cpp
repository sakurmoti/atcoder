#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,D;
    cin >> N >> D;

    vector<pair<int,int>> work(N);
    for(int i = 0; i < N; i++){
        cin >> work[i].first >> work[i].second;
    }

    //取り掛かれる仕事のうち、報酬が大きい順に仕事
    sort(work.begin(), work.end(), [](auto x, auto y){return x.second > y.second;});

    //scheduleはi番目の仕事をするかどうか。するならfalse
    vector<bool> schedule(N, true);
    long long ans = 0;
    for(int day = 1; day <= D; day++){
        for(int i = 0; i < N; i++){
            if(schedule[i] && work[i].first <= day){
                schedule[i] = false;
                ans += work[i].second;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}