#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    vector<string> cut = {"maerd", "remaerd", "esare", "resare"};
    
    for(int i = 0; i < S.size();){
        bool flag = false;
        for(int j = 0; j < 4; j++){
            if(S.substr(i, cut.at(j).size()) == cut.at(j)){
                flag = true;
                i+=cut.at(j).size();
            }
        }

        if(!flag){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}