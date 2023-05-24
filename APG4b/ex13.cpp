#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,sum=0;
    cin >> N;
    
    vector<int> score(N);
    for(int i = 0; i < N; i++){
        cin >> score.at(i);
        sum += score.at(i);
    }

    int ave = sum/N;
    for(int i = 0; i < N; i++){
        cout << abs(score.at(i) - ave) << endl;
    }
    return 0;
}