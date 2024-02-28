#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> P(N);
    for(auto &_v : P) cin >> _v;
    
    int Q; cin >> Q;
    while(Q--){
        int a,b;
        cin >> a >> b;

        for(int i = 0; i < N; i++){
            if(P[i] == a){
                cout << a << endl;
                break;
            }else if(P[i] == b){
                cout << b << endl;
                break;
            }
        }
    }
    return 0;
}