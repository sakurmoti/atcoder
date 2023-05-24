#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(N));
    for(int i = 0; i < M; i++){
        int U,V;
        cin >> U >> V;
        graph.at(U-1).at(V-1) = 1;
        graph.at(V-1).at(U-1) = 1;
    }

    int count=0;
    for(int i = 0; i < N; i++){
        for(int j = i; j < N; j++){
            for(int k = j; k < N; k++){
                if(graph.at(i).at(j)==1 && graph.at(j).at(k)==1 && graph.at(k).at(i)==1){
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}