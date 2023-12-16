#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    int t,x;
    vector<pair<int, int>> query(N);
    for(int i = 0; i < N; i++){
        cin >> t >> x;
        x--;
        query[i] = make_pair(t,x);
    }

    // 勝つことはできるか
    {
        bool lose = false;
        vector<int> potion(N);
        for(int i = 0; i < N; i++){
            tie(t,x) = query[i];
            if(t==1) potion[x]++;
            else potion[x]--;
            
            if(potion[x] < 0) lose = true;
        }

        if(lose){
            cout << -1 << endl;
            return 0;
        }
    }

    // 勝つための最小パターンは?
    {
        // 最後でポーションが余ってはいけない
        // クエリ逆読みでポーションが必要なら拾う
        vector<int> cmd;
        vector<int> must(N, 0);
        for(int i = N-1; i >= 0; i--){
            tie(t,x) = query[i];

            if(t==1){
                if(must[x] > 0){
                    // 拾う
                    cmd.push_back(1);
                    must[x]--;
                }else{
                    cmd.push_back(0);
                }

            }else{
                must[x]++;
                cmd.push_back(-1);
            }
        }

        int C = cmd.size();
        reverse(ALL(cmd));
        
        int Kmin = -1;
        int cnt = 0;
        for(int i = 0; i < C; i++){
            if(cmd[i] == 1) cnt++;
            else if(cmd[i] == -1){
                cnt--;
            }

            Kmin = max(Kmin, cnt);
        }

        cout << Kmin << endl;
        for(int i = 0; i < cmd.size(); i++){
            if(cmd[i] == -1) continue;
            cout << cmd[i];
            if(i != cmd.size()-1) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}