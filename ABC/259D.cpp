#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    ll sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    vector<tuple<ll,ll,ll>> circle(N);
    for(int i = 0; i < N; i++){
        ll x,y,r;
        cin >> x >> y >> r;
        circle[i] = make_tuple(x,y,r);
    }

    auto isOnCircle = [&](int idx, ll x, ll y) -> bool {
        ll X,Y,R;
        tie(X,Y,R) = circle[idx];
        return (X-x)*(X-x) + (Y-y)*(Y-y) == R*R;
    };

    int s_idx,t_idx;
    for(int i = 0; i < N; i++){
        if(isOnCircle(i, sx, sy)){
            s_idx = i;
        }

        if(isOnCircle(i, tx, ty)){
            t_idx = i;
        }
    }

    // 円uと円vが交差していればu-vの無向パスを追加する
    auto isIntersect = [&](int u, int v) -> bool {
        ll ux,uy,ur, vx,vy,vr;
        tie(ux,uy,ur) = circle[u];
        tie(vx,vy,vr) = circle[v];

        // ur-uv <= sqrt(dist) <= ur+vr
        ll dist = (ux-vx)*(ux-vx) + (uy-vy)*(uy-vy);
        ll Rp = (ur+vr)*(ur+vr);
        ll Rm = (ur-vr)*(ur-vr);

        return Rm <= dist && dist <= Rp;
    };

    vector<vector<int>> G(N);
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(isIntersect(i,j)){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }

    // for(int i = 0; i < N; i++){
    //     printf("%d : ", i);
    //     for(int j = 0; j < G[i].size(); j++){
    //         printf("%d ", G[i][j]);
    //     }
    //     printf("\n");
    // }

    queue<int> que;
    vector<bool> visited(N, false);
    que.push(s_idx);
    while(!que.empty()){
        int v = que.front();
        que.pop();

        if(visited[v]) continue;
        visited[v] = true;

        for(int i = 0; i < G[v].size(); i++){
            que.push(G[v][i]);
        }
    }

    if(visited[t_idx]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}