#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,Q; cin >> N >> Q;

    vector<set<int>> box(N);
    for(int i = 0; i < N; i++){
        int c; cin >> c;
        box[i].insert(c);
    }

    for(int q = 0; q < Q; q++){
        int a,b; cin >> a >> b;
        a--;
        b--;

        if(box[a].size() <= box[b].size()){
            // box[a]を全てbox[b]に移す
            box[b].merge(box[a]);
            box[a].clear();

        }else{
            // box[b]を全てbox[a]に移した後、box[a]とbox[b]を入れ替える
            box[a].merge(box[b]);
            box[b].clear();

            swap(box[a], box[b]);
        }

        cout << box[b].size() << endl;
    }
    return 0;
}