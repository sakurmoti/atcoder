#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> box(N+1); //box[i]に入ってる数を表す
    vector<set<int>> card(1e6); //card[i]は数iが入ってる箱を答える
    for (int i = 1; i <= Q; i++) {
        int op, x, y;
        cin >> op >> x;

        if(op == 1){
            cin >> y;
            card[x].insert(y);
            box[y].push_back(x);

        }else if (op == 2) {
            sort(box[x].begin(), box[x].end());
            
            int M = box[x].size();
            for(int j = 0; j < M; j++){
                cout << box[x][j] << " \n"[j==M-1];
            }
            
        }else if (op == 3) {
            for(auto itr = card[x].begin(); itr != card[x].end(); itr++){
                cout << *(itr) << " \n"[next(itr) == card[x].end()];
                
            }
        }
    }

    return 0;
}
