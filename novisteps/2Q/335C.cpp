#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,Q; cin >> N >> Q;

    vector<pair<int, int>> head;
    for(int i = N; i >= 1; i--){
        head.push_back(make_pair(i,0));
    }

    map<char, pair<int, int>> d;
    d['R'] = {1,0};
    d['L'] = {-1,0};
    d['U'] = {0,1};
    d['D'] = {0,-1};

    while(Q--){
        int q; cin >> q;

        if(q == 1){
            char c; cin >> c;
            auto prev = *head.rbegin();
            head.push_back(make_pair(prev.first + d[c].first, prev.second + d[c].second));

        }else{
            int p; cin >> p;
            auto ans = prev(head.end(), p);
            cout << ans->first << " " << ans->second << endl;

        }
    }
    return 0;
}