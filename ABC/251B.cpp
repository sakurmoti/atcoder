#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,W;
    cin >> N >> W;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    int count=0;
    int sum1=W+1,sum2=W+1,sum3=W+1;
    set<int> goodNumber;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            for(int k = j+1; k < N; k++){
                sum3 = A.at(i) + A.at(j) + A.at(k);
                if(sum3 <= W && !goodNumber.count(sum3)){
                    count++;
                    goodNumber.insert(sum3);
                }

            }

            sum2 = A.at(i) + A.at(j);
            if(sum2 <= W && !goodNumber.count(sum2)){
                count++;
                goodNumber.insert(sum2);
            }
        }

        sum1 = A.at(i);        
        if(sum1 <= W && !goodNumber.count(sum1)){
            count++;
            goodNumber.insert(sum1);
        }
    }

    cout << count << endl;

    return 0;
}