#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,X;
    cin >> N >> X;
    
    vector<long long> A(N);
    for(auto &v : A) cin >> v;

    sort(A.begin(), A.end());
    
    //尺取り
    for(int i=0,j=0; i<N && j<N; ){
        long long dis = A[i]-A[j];

        if(dis == X){
            cout << "Yes" << endl;
            return 0;

        }else if(dis < X){
            i++;

        }else if(dis > X){
            j++;
        }
    }
    cout << "No" << endl;
    return 0;
}