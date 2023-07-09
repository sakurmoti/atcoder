#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int A,B;
    cin >> A >> B;

    int x,y;
    vector<vector<int>> num(10, vector<int>(10,-1));
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            num[i][j] = 3*(i-1)+j;
            
            if(num[i][j] == A){
                x = j;
                y = i;
            }
        }
    }
    
    int dx[] = {1,-1};
    for(int i = 0; i < 2; i++){
        if(num[y][x+dx[i]] == B){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}