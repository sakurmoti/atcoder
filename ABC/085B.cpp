#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> d(N);
    for(int i = 0; i < N; i++){
        cin >> d.at(i);
    }

    sort(d.begin(), d.end());

    set<int> Q;
    int ans=0;
    for(int i = 0; i < N; i++){
        if(!Q.count(d.at(i))){
            Q.insert(d.at(i));
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}