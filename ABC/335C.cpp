#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,Q; cin >> N >> Q;

    vector<pair<int, int>> head(N);
    for(int i = 0; i < N; i++){
        head[i] = make_pair(N-i, 0);
    }

    map<char, pair<int, int>> dict;
    dict['R'] = make_pair(1, 0);
    dict['L'] = make_pair(-1, 0);
    dict['U'] = make_pair(0, 1);
    dict['D'] = make_pair(0, -1);

    while(Q--){
        int cmd; cin >> cmd;    
        int n = head.size();

        if(cmd == 1){
            char c; cin >> c;
            int f = head[n-1].first + dict[c].first;
            int s = head[n-1].second + dict[c].second;
            head.push_back(make_pair(f, s));
        
        }else{
            int p; cin >> p;
            printf("%d %d\n", head[n-p].first, head[n-p].second);
        }

    }
    return 0;
}