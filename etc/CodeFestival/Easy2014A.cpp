#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int preA,A;
    long long sum=0;
    for(int i = 0; i < N; i++){
        if(i == 0){
            cin >> preA;

        }else{
            cin >> A;
            sum += (A-preA);
            preA = A;

        }
    }

    double ave = (double)sum / (N-1);
    cout << fixed << setprecision(6) << ave << endl;
    return 0;
}