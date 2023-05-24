#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,L;
    cin >> N >> L;

    vector<int> E,W;
    E.push_back(L);
    W.push_back(0);
    for(int i = 0; i < N; i++){
        int a;
        char c;
        cin >> a >> c;

        if(c == 'E') E.push_back(a);
        else W.push_back(a);
    }

    sort(E.begin(), E.end(), [](auto x, auto y){return x < y;});
    sort(W.begin(), W.end(), [](auto x, auto y){return x > y;});

    int e = *E.begin();
    int w = *W.begin();

    cout << max(L-e,w) << endl;
    return 0;
}