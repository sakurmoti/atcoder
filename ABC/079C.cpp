#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s; cin >> s;
    int A = s[0] - '0';

    int num[3];
    num[0] = s[1] - '0';
    num[1] = s[2] - '0';
    num[2] = s[3] - '0';
    
    for(int i = 0; i < (1 << 3); i++){
        bitset<3> bits(i);
        vector<char> sign(3);

        int calc = A;
        for(int j = 0; j < 3; j++){
            if(bits.test(j)){
                //plus
                sign[j] = '+';
                calc += num[j];
            }else{
                //minus
                sign[j] = '-';
                calc -= num[j];
            }
        }

        if(calc == 7){
            cout << A;
            for(int j = 0; j < 3; j++){
                cout << sign[j] << num[j];
            }
            cout << "=7" << endl;
            return 0;
        }
    }

    return 0;
}