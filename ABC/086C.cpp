#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> t(N+1), x(N+1), y(N+1);
    x.at(0) = y.at(0) = t.at(0) = 0;
    for(int i = 1; i <= N; i++){
        cin >> t.at(i) >> x.at(i) >> y.at(i);
    }

    bool flag=true;
    for(int i = 0; i < N; i++){
        int dx = abs(x.at(i+1) - x.at(i));
        int dy = abs(y.at(i+1) - y.at(i));
        int dt = abs(t.at(i+1) - t.at(i));

        int time = dx + dy;

        if(!(time<=dt && (time-dt)%2==0 )){
            flag = false;
        }

    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}