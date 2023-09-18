#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct point{
    ll x;
    ll y;

    point operator+(const point &other){
        return {x+other.x, y+other.y};
    }

    point operator-(){
        return {-x,-y};
    }
};

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<pair<int, point>>> A(N+1);
    for(int i = 1; i <= M; i++){
        int a,b;
        point p;
        cin >> a >> b >> p.x >> p.y;

        A[a].push_back(make_pair(b,p));
        A[b].push_back(make_pair(a, -p));
    }

    vector<bool> visited(N+1, false);
    vector<point> ans(N+1, {0,0});

    auto dfs = [&](auto dfs, int a) -> void {
        if(visited[a]) return;
        visited[a] = true;

        for(int i = 0; i < A[a].size(); i++){
            int b = A[a][i].first;
            point p = A[a][i].second;

            ans[b] = {ans[a].x + p.x, ans[a].y + p.y};
            dfs(dfs, b);
        }

    };

    dfs(dfs, 1);

    for(int i = 1; i <= N; i++){
        if(visited[i]){
            cout << ans[i].x << " " << ans[i].y << endl;
        }else{
            cout << "undecidable" << endl;
        }
    }
    return 0;
}