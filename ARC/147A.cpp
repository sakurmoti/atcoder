#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A.at(i);

    int count=0;
    for(int i = 0; A.size() > 1; i++,count++){
        if(A[i] > A.at(i+1)){
            A[i] = A[i] % A[i+1];
            if(A[i]==0) A.erase(A.begin()+i);
        }else{
            A[i+1] = A[i+1] % A[i];
            if(A[i+1]==0) A.erase(A.begin()+i+1);
        }

        if(i+1 >= A.size()-1) i=-1;

    }

    cout << count << endl;

    return 0;
}