#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> a(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i).first;
        a.at(i).second = i+1;
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    for(int i = 0; i < N; i++){
        cout << a.at(i).second << endl;
    }
    return 0;
}