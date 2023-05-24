#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> A(5);
    cin >> A.at(0) >> A.at(1) >> A.at(2) >> A.at(3) >> A.at(4);

    bool flag = true;
    for(int i = 0; i < 5; i++){
        int count=0;
        for(int j = 0; j < 5; j++){
            if(A.at(i) == A.at(j)) count++;
        }

        if(count == 2 || count == 3);
        else flag = false;

    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}