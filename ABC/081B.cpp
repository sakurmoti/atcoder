#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);

    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    int ans=10000;
    for(int i = 0; i < N; i++){
        int count=0;
        while(true){
            if(A.at(i)%2 == 0){
                A.at(i) /= 2;
                count++;
            }else{
                break;
            }
        }

        ans = min(ans,count);
    }

    cout << ans << endl;
    return 0;
}