#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define DEBUG(x) cerr << #x << " : " << x << endl;

int main(){
    int N,M; cin >> N >> M;
    vector<tuple<int, int, int>> city(M);
    for(int i = 0; i < M; i++){
        int P,Y;
        cin >> P >> Y;

        city[i] = make_tuple(P, Y, i);
    }

    sort(ALL(city));

    vector<pair<int, int>> ans(M);
    vector<int> idx(N+1, 0);
    for(int i = 0; i < M; i++){
        int P,Y,I;
        tie(P,Y,I) = city[i];

        // printf("P=%d, Y=%d, I=%d\n",P,Y,I);

        idx[P]++;
        ans[I] = make_pair(P, idx[P]);
    }

    for(int i = 0; i < M; i++){
        printf("%06d%06d\n",ans[i].first, ans[i].second);
    }
    return 0;
}  