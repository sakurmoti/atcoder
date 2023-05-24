#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,M;
    cin >> H >> M;

    int A,B,C,D;
    /*AB:CDとAC:BDの両方が正しい表示の時
    それは0 <= AB,AC <= 23 && 0 <= CD,BD <= 59のとき*/
    A = H/10;
    B = H - 10*A;
    C = M/10;
    D = M - 10*C;

    while(true){
        int AB = 10*A + B;
        int AC = 10*A + C;
        int CD = 10*C + D;
        int BD = 10*B + D;

        if(AB <=23 && AC <= 23 && CD <= 59 && BD <= 59){
            cout << AB << " " << CD << endl;
            break;
        }

        D++;
        if(D >= 10){
            D = 0;
            C++;
            if(C >= 6){
                C = 0;
                B++;
                if(B >= 10){
                    B = 0;
                    A++;
                    if(A >= 3){
                        A = 0;
                    }
                }
            }
        }
    }
    return 0;
}