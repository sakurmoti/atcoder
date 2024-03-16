#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    
    vector<int> imos(3e5, 0);
    for(int i = 0; i < N; i++){
        int L,R;
        cin >> L >> R;

        imos[L]++;
        imos[R]--;
    }


    for(int i = 1; i < imos.size(); i++){
        imos[i] += imos[i-1];
    }


    for(int i = 1; i < imos.size() -1; i++){
        if(imos[i-1] <= 0 && imos[i] > 0){
            cout << i << " ";
        }

        if(imos[i] > 0 && imos[i+1] <= 0){
            cout << i+1 << endl;
        }
    }
    return 0;
}