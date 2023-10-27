#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

#include <atcoder/all>
using namespace atcoder;

int main(){
    int N; cin >> N;
    vector<pair<int, int>> p(N);
    for(int i = 0; i < N; i++){
        cin >> p[i].first >> p[i].second;
    }

    dsu d(N);
    vector<pair<int, int>> dxy = { {-1,-1}, {-1,0}, {0,-1}, {0,1}, {1,0}, {1,1} };
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            for(int k = 0; k < 6; k++){
                if(p[i].first + dxy[k].first == p[j].first && p[i].second + dxy[k].second == p[j].second){
                    d.merge(i,j);
                }
            }
        }
    }

    // vector<vector<int>> g = d.groups();
    // for(int i = 0; i < g.size(); i++){
    //     for(int j = 0; j < g[i].size(); j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << d.groups().size() << endl;
    return 0;
}