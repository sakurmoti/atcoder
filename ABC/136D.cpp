#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    string S; cin >> S;
    int N = S.size();

    // RLでループするのでRLのうちRの位置を記録
    vector<int> rl;
    for(int i = 0; i < N-1; i++){
        if(S[i] == 'R' && S[i+1] == 'L'){
            rl.push_back(i);
        }
    }

    vector<int> A(N,0);
    for(int i = 0; i < N; i++){
        int idx,d;
        if(S[i] == 'R'){
            idx = *lower_bound(ALL(rl), i);
            d = abs(i - idx);
        }else{
            idx = *prev(lower_bound(ALL(rl), i));
            d = abs(i - idx);
        }
        
        // cerr << idx << " " << d << endl;
        if(d%2 == 0){
            A[idx]++;
        }else{
            A[idx+1]++;
        }
    }

    for(auto &_v : A) cout << _v << " "; cout << endl;
    return 0;
}