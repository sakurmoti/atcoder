#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<int> vec(5);
    for(int i = 0; i < 5; i++){
        cin >> vec.at(i);
    }

    string ans = "NO";
    for(int i = 0; i < 4; i++){
        if(vec.at(i) == vec.at(i+1)){
            ans = "YES";
        }
    }
    cout << ans << endl;
    return 0;
}