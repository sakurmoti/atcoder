#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> X(N),Y(N);
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
    }

    auto f = [&](int i, int j){
            int x1 = X[i];
            int y1 = Y[i];

            int x2 = X[j];
            int y2 = Y[j];
        
            return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };

    for(int i = 0; i < N; i++){
        int dist = -1;
        int ans = -1;
        for(int j = 0; j < N; j++){
            int d = f(i,j);
            if(dist < d){
                dist = d;
                ans = j+1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}