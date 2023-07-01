#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    vector<int> s(10, 0);
    for(int i = 1; i <= 8; i++){
        cin >> s[i];

        if( (s[i-1] <= s[i]) && (100 <= s[i] && s[i] <= 675) && (s[i] %25 == 0) ){
            
        }else{
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    
    return 0;
}