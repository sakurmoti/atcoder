#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;

    map<int, int> P;
    vector<int> ans(N+1);
    int next;
    for(int i = 1; i <= N; i++){
        int a; cin >> a;
        if(a < 0){
            ans[0] = i;
            next = i;
        }else{
            P[a] = i;
        }
    }

    for(int i = 1; i < N; i++){
        ans[i] = P[next];
        next = ans[i];
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << " \n"[i == N-1];
    }

    return 0;
}