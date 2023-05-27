#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,H,K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;

    set<pair<int, int>> item;
    for(int i = 0; i < M; i++){
        int x,y;
        cin >> x >> y;

        item.insert(make_pair(x,y));
    }

    pair<int, int> now = {0,0};
    for(int i = 0; i < N; i++){
        H--;
        if(H < 0){
            cout << "No" << endl;
            return 0;
        }

        char c = S[i];
        if(c == 'U'){
            now.second++;
        }

        if(c == 'R'){
            now.first++;
        }

        if(c == 'D'){
            now.second--;
        }

        if(c == 'L'){
            now.first--;
        }

        if(item.count(now)){
            if(H < K){
                H = K;
                item.erase(now);
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
}