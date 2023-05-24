#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> road(N+1);
    int a,b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;

        road.at(a).push_back(b);
        road.at(b).push_back(a);
    }

    for(int i = 1; i <= N; i++){
        cout << road.at(i).size() << endl;
    }
    return 0;
}