#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<vector<int>> A(N+1, vector<int> (N+1));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> A[i][j];
        }
    }

    int Q;
    cin >> Q;

    int opr,x,y;
    vector<int> row(N+1);
    for(int i = 0; i <= N; i++) row[i] = i;

    for(int q = 0; q < Q; q++){
        cin >> opr >> x >> y;
        
        if(opr == 1){
            //rowは行の並びを表す
            int tmp = row[x];
            row[x] = row[y];
            row[y] = tmp;

        }else if(opr == 2){
            cout << A[row[x]][y] << endl;

        }
    }
    return 0;
}