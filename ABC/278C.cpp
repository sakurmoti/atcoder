#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;

    map<int, map<int, bool>> follow;
    for(int query = 0; query < Q; query++){
        int t,a,b;
        cin >> t >> a >> b;
        
        if(t == 1){
            follow[a][b] = true;

        }else if(t == 2){
            follow[a][b] = false;

        }else if(t == 3){
            if(follow[a][b] && follow[b][a]){
                cout << "Yes" << endl;
            
            }else{
                cout << "No" << endl;
            }

        }

    }
    return 0;
}