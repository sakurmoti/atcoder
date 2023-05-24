#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    char t;
    int x;
    int A = 0;
    int modulo = 10000;
    for(int i = 0; i < N; i++){
        cin >> t >> x;

        if(t == '+'){
            A += x;

        }else if(t == '-'){
            A -= x;
            if(A < 0){
                A += modulo;
            }

        }else if(t == '*'){
            A *= x;

        }else{
            cout << "ERROR";
            return 0;
        }
        
        A %= modulo;
        cout << A << endl;

    }
    return 0;
}