#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    int X=0, Y=0;
    for(int i = 0; i < N; i++){
        int x,y;
        cin >> x >> y;

        X += x;
        Y += y;
    }


    if(X == Y){
        cout << "Draw" << endl;
    }else if(X > Y){
        cout << "Takahashi" << endl;
    }else{
        cout << "Aoki" << endl;
    }
    return 0;
}