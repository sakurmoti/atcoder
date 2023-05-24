#include <bits/stdc++.h>
using namespace std;

int N,X,Y;
vector<vector<int>> tree(200010);
vector<int> ans;
vector<bool> mapping(200010,false);

bool flag = false;

void dfs(int root){
    //printf("now %d\n",root);
    mapping.at(root) = true;
    ans.push_back(root);
    
    if(root == Y){
        flag = true;
        return;
    }

    for(int i = 0; i < tree.at(root).size(); i++){
        //訪れてなければいく
        if(!mapping.at(tree.at(root).at(i))){
            dfs(tree.at(root).at(i));

            if(flag) return;
        }
    }

    ans.erase(ans.end()-1);
}

int main(){
    cin >> N >> X >> Y;

    for(int i = 0; i < N-1; i++){
        int u,v;
        cin >> u >> v;

        //頂点uからvへのパスがあることを指す
        tree.at(u).push_back(v);

        //逆もまた然り
        tree.at(v).push_back(u);

    }

    //木ができたのでこれを探索する
    dfs(X);

    for(int i = 0; i < ans.size(); i++){
        cout << ans.at(i);
        
        if(i != ans.size()-1) cout <<" ";
        else cout << endl;
    }

    return 0;
}