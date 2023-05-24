#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,P,Q,R,S;
    cin >> N >> P >> Q >> R >> S;
    
    vector<int> A(N+1);
    for(int i = 1; i <= N; i++) cin >> A[i];

    int c = 0;
    int d = 0;
    for(int i = 1; i <= N; i++){
        if(P <= i && i <= Q){
            cout << A.at(R+c);
            c++;
        
        }else if(R <= i && i <= S){
            cout << A.at(P+d);
            d++;

        }else{
            cout << A.at(i);

        }

        if(i == N) cout << endl;
        else cout << " ";
    }
    return 0;
}