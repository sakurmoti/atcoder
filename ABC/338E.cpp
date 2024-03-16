#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<pair<int, int>> C(2*N);
    for(int i = 0; i < N; i++){
        int a,b; cin >> a >> b;

        a--; b--;
        if(a > b) swap(a, b); // aが先に来るように調整

        C[a] = {-1, i}; // 頂点aは括弧列の左(-1) と 弧i である情報を持たせる
        C[b] = {1, i};
    }

    // 円を切り開いて線分で考える
    // すると括弧が正しく閉じているかに対応
    stack<int> stk;
    for(int i = 0; i < 2*N; i++){
        auto [t, v] = C[i];
        
        if(t < 0){
            stk.push(v);

        }else{
            int u = stk.top();
            stk.pop();

            if(u != v){
                // 括弧の終わりが異なる = 弧が異なる = 交点あり
                cout <<  "Yes" << endl;
                return 0;
            }

        }

    }
    
    cout << "No" << endl;
    return 0;
}