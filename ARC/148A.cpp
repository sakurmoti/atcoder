#include <bits/stdc++.h>
using namespace std;

//模写
int gcdd(long long a, long long b){
    if(a%b == 0){
        return b;
    }else{
        return gcdd(b, a%b);
    }
}

int main(){
    int N;
    cin >> N;

    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >>A.at(i);
    }

    int g = 0;
    for(int i = 0; i < N-1; i++){
        if(A[i]-A[i+1] != 0){
            g = gcdd(g, abs(A[i]-A[i+1]));
        }
        //cout << g << endl;
    }

    if(g == 1) cout << 2 << endl;
    else cout << 1 << endl;
    
    return 0;
}