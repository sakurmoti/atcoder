#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> Graph(N+1);
    for(int i = 0; i < M; i++){
        int u,v;
        cin >> u >> v;

        Graph.at(u).push_back(v);
        Graph.at(v).push_back(u);
    }

    for(int i = 1; i <= N; i++){
        printf("%d: {", i);
        
        for(int j = 0; j < Graph.at(i).size(); j++){
            printf("%d", Graph.at(i).at(j));

            if(j != Graph.at(i).size()-1){
                printf(", ");
            
            }
        }
        printf("}\n");
    }
    return 0;
}