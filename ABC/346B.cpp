#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int W,B; cin >> W >> B;

    string S = "wbwbwwbwbwbw";
    int N = S.size();

    for(int i = 0; i < N; i++){
        int cntW = 0;
        int cntB = 0;
        for(int j = 0; j < W+B; j++){
            if(S[ (i+j) % N] == 'w'){
                cntW++;
            }else{
                cntB++;
            }
        }

        if(cntW == W && cntB == B){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}