#include <bits/stdc++.h>
using namespace std;

int N;
map<int, vector<int>> ladder;
set<int> isCome;

int ans = 1;

void dfs(int floor){
    if(ans < floor) ans = floor;
    isCome.insert(floor);

    for(int i = 0; i < ladder.at(floor).size(); i++){
        if(!isCome.count(ladder.at(floor).at(i))){
            dfs(ladder.at(floor).at(i));
        }
    }

}

int main(){
    cin >> N;

    ladder[1].push_back(1);
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;

        ladder[a].push_back(b);
        ladder[b].push_back(a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}