#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> road;
vector<vector<int>> tree;
vector<bool> isCome;

void bfs(int first, int start){
    if(isCome.at(start)){
        return;
    }

    isCome.at(start) = true;
    for(int i = 0; i < tree.at(start).size(); i++){
        //printf("%d to %d\n",first,tree.at(start).at(i));
        
        road.at(first).at(tree.at(start).at(i)) = true;
        bfs(first, tree.at(start).at(i));
    }
}

int main(){
    int N,M;
    cin >> N >> M;


    road.resize(N+1, vector<bool>(N+1, false));
    tree.resize(N+1);

    for(int i = 1; i <= N; i++) road.at(i).at(i) = true;
    
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;

        tree.at(a).push_back(b);
    }

    //iの街から行けるところをroadに書く
    for(int i = 1; i <= N; i++){
        isCome.resize(0);
        isCome.resize(N+1, false);
        bfs(i, i);
    }

    //iからjにいけるかシュミレーション O(N^2)
    int count=0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(road.at(i).at(j)){
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}