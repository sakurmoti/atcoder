#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M; cin >> N >> M;
    vector<vector<char>> S(N+1, vector<char>(M+1, '&'));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> S[i][j];
        }
    }

    for(int i = 1; i <= N-8; i++){
        for(int j = 1; j <= M-8; j++){
            bool flag = true;
            
            for(int y = 0; y < 9; y++){
                for(int x = 0; x < 9; x++){
                    char c = S[i+y][j+x];
                    
                    if( (x<3 && y<3) || (x>6 && y>6) ){
                        //黒でないといけない
                        if(c != '#') flag = false;
                    }

                    if( (x==3 && y<=3) || (x<=3 && y==3) || (x==5 && y>=5) || (x>=5 && y==5)){
                        //白出ないといけない
                        if(c != '.') flag = false;
                    }
                    
                }
            }

            if(flag){
                cout << i << " " << j << endl;
            }

        }
    }
    return 0;
}