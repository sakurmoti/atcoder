#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;

    int count=0;
    char c;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> c;
            if(c == '#') count++;
        }
    }
    cout << count << endl;
    return 0;
}