#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string A,B;
    cin >> A >> B;

    //A,Bの上の桁から順に、それぞれ9,1にするのが最適
    int ans = -1000;
    for(int i = 0; i < 3; i++){
        string nA = A;
        string nB = B;
        nA[i] = '9';
        nB[i] = "01"[i==0]; //trueなら1

        ans = max({ans, stoi(nA)-stoi(B), stoi(A)-stoi(nB)});
        // printf("nA-B = %d, A-nB = %d\n", stoi(nA)-stoi(B), stoi(A)-stoi(nB));
    }
    cout << ans << endl;
    return 0;
}