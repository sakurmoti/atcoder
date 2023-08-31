#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string A,B,C;
    cin >> A >> B >> C;

    int a=0,b=0,c=0;
    char now = 'a';
    while(true){
        if(now == 'a'){
            if(a >= A.size()){
                cout << 'A' << endl;
                break;
            }
            now = A[a];
            a++;

        }else if(now == 'b'){
            if(b >= B.size()){
                cout << 'B' << endl;
                break;
            }
            now = B[b];
            b++;

        }else if(now == 'c'){
            if(c >= C.size()){
                cout << 'C' << endl;
                break;
            }
            now = C[c];
            c++;

        }
    }
    return 0;
}