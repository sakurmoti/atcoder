#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &v : A) cin >> v;

    int cnt = 0;
    set<int> s;
    for(int i = 0; i < N; i++){
        if(s.find(A[i]) == s.end()){
            s.insert(A[i]);
            cnt++;
        }else{
            s.erase(A[i]);
            cnt--;
        }
    }
    cout << cnt << endl;
    return 0;
}