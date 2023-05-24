#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,T;
    cin >> N >> M >> T;

    vector<int> A(N);
    vector<int> X(M+1),Y(M+1);
    for(int i = 1; i < N; i++) cin >> A.at(i);
    for(int i = 0; i < M; i++) cin >> X.at(i) >> Y.at(i);

    long long time = T;
    int bonus=0;
    for(int i = 1; i < N; i++){
        if(time > A.at(i)){
            time -= A.at(i);
            if(i+1 == X.at(bonus)){
                time += Y.at(bonus);
                bonus++;
            }

        }else{
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}