#include <bits/stdc++.h>
using namespace std;

int N,D;
vector<int> X,Y;
vector<bool> infected;
vector<bool> visited;
int dist(int i, int j){
    return ( (X[j]-X[i])*(X[j]-X[i]) + (Y[j]-Y[i])*(Y[j]-Y[i]) );
}

void virus(int k){
    if(visited[k]) return;
    visited[k] = true;

    for(int i = 0; i < N; i++){
        if(dist(k,i) <= D*D){
            infected[i] = true;
            virus(i);
        }
    }
}

int main(){
    cin >> N >> D;

    X.resize(N);
    Y.resize(N);
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
    }

    infected.resize(N, false);
    infected[0] = true;
    
    visited.resize(N, false);
    virus(0);

    for(int i = 0; i < N; i++){
        if(infected[i]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}