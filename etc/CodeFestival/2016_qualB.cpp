#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,A,B;
    cin >> N >> A >> B;
    string S; cin >> S;

    int entry = 0;
    int outside = 1;
    for(int i = 0; i < N; i++){
        if(entry >= A+B){
            cout << "No" << endl;
            continue;
        }

        if(S[i] == 'a'){
            cout << "Yes" << endl;
            entry++;
        }

        if(S[i] == 'b'){
            if(outside <= B){
                cout << "Yes" << endl;
                entry++;
            }else{
                cout << "No" << endl;
            }
            outside++;
        }

        if(S[i] == 'c'){
            cout << "No" << endl;
        }
    }
    return 0;
}