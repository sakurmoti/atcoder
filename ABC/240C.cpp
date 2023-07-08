#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,X;
    cin >> N >> X;
    
    vector<bool> line(X+1000, false);
    line[0] = true;
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;

        vector<int> s;
        for(int j = 0; j <= X; j++){
            if(line[j]){
                line[j] = false;
                s.push_back(j);
            }
        }

        for(int j = 0; j < s.size(); j++){
            line[s[j]+a] = true;
            line[s[j]+b] = true;
        }
    }

    if(line[X]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}