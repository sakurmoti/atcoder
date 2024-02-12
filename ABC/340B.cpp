#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int Q; cin >> Q;

    vector<int> A;
    while(Q--){
        int a,x;
        cin >> a >> x;

        if(a == 1){
            A.push_back(x);

        }else if(a == 2){
            cout << A[A.size()-x] << endl;
        }
    }
    return 0;
}