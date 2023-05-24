#include <bits/stdc++.h>
using namespace std;

int main(){
    int Q;
    cin >> Q;

    map<string, int> file;
    for(int i = 0; i < Q; i++){
        int cmd;
        cin >> cmd;
        
        if(cmd == 1){
            string x;
            int y;
            cin >> x >> y;

            file[x] = y;

        }else{
            string x;
            cin >> x;

            cout << file.at(x) << endl;
        }
    }
    return 0;
}