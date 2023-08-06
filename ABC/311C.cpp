#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    int now = 1;
    for(int i = 0; i < N; i++){ //N回移動すると必ず閉路に入る
        int next = A[now];
        now = next;
    }

    int v = now;
    vector<int> tour;
    do{
        tour.push_back(now);
        now = A[now];

    }while(v != now);

    cout << tour.size() << endl;
    for(auto &v : tour) cout << v << ' ';

    return 0;
}