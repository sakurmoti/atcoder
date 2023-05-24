#include <bits/stdc++.h>
using namespace std;

int N;
map<string, string> Graph;
map<string, string> revGraph;
map<string, bool> visited;
vector<string> S,T;

bool flag = true;

void dfs1(string key){
    string next = Graph.at(key);

    if(visited.at(key)){
        //帰ってきた -> 閉路
        flag = false;
        //cout << "dfs1 " << key << endl;
        return;
    
    }else{
        visited.at(key) = true;

    }

    if(!visited.count(next)){
        //visitedに次が存在しないならTの名前はいつでも変えられる
        return;
    }

    dfs1(next);

}

void dfs2(string key){
    //逆にもたどる
    if(visited.at(key)){
        //帰ってきた -> 閉路
        flag = false;
        //cout << "dfs2 " << key << endl;
        return;
    
    }else{
        visited.at(key) = true;

    }
    
    //keyが根であるとき
    if(!revGraph.count(key)) return;

    string prev = revGraph.at(key);
    dfs2(prev);

}

int main(){
    cin >> N;

    S.resize(N);
    T.resize(N);
    //SからTへのパスをつなげた時、グラフが閉路にならなければok
    for(int i = 0; i < N; i++){
        cin >> S[i] >> T[i];

        Graph[S[i]] = T[i];
        revGraph[T[i]] = S[i];
        visited[S[i]] = false;
    }

    //閉路になっているか確認
    for(int i = 0; i < N; i++){
        string key = S[i];

        //cout << i << endl;
        if(!visited[key]){
            dfs1(key);

            if(revGraph.count(key)){
                dfs2(revGraph.at(key));
            }

        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}